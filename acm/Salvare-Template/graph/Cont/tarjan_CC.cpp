//边连通分量
struct edge
{
    int y,pdc,next;
    edge(int y_=0,int pdc_=0,int n_=0){y=y_,pdc=pdc_,next=n_;}
}e[2000005];
int head[1005],mm;  //mm=0  head 初始化 -1
vector<int>bri[2];  //桥 初始化
bool vis[1005];   //初始化全 0
int low[1005],dfn[1005];
int edc[1005];
int stack[1005],sk;
bool cut[1005];   //割点 初始化全 0
int ecnt,timer,root;    //timer 初始化为 0 cnt 初始化为 1 root 为根
void dfs(int s,int fa)
{
	dfn[s]=low[s]=++timer;
	stack[sk++]=s;
	int to,sz=0;
	bool flag=vis[s]=1;
	for(int i=head[s];~i;i=e[i].next)
		if((to=e[i].y)==fa&&flag)flag=0;
		else
        {
            if(vis[to])low[s]=min(dfn[to],low[s]);
            else
            {
                dfs(to,s);sz++;
                low[s]=min(low[to],low[s]);
                if(low[to]>=dfn[s])
                {
                    if(s!=root||sz>1)cut[s]=1;
                }
                if(low[to]>dfn[s])
                {
                    bri[0].push_back(s);
                    bri[1].push_back(to);
                }
            }
        }
    if(low[s]==dfn[s])
    {
        do edc[stack[--sk]]=ecnt;
        while(stack[sk]!=s);
        ecnt++;
    }
}
void add(int x,int y)
{
    e[mm]=edge(y,0,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}


struct edge
{
    int y,pdc,next;
    edge(int y_=0,int pdc_=0,int n_=0){y=y_,pdc=pdc_,next=n_;}
}e[2000005];
int head[1005],mm;
bool vis[1005];
int low[1005],dfn[1005];
int stack2[2000005],sk2;
bool cut[1005];
int pcnt,timer,root;
void dfs(int s,int fa)
{
	dfn[s]=low[s]=++timer;
	int to,sz=0;
	bool flag=vis[s]=1;
	for(int i=head[s];~i;i=e[i].next)
        if(e[i].pdc==0)
        {
            stack2[sk2++]=i;
            if((to=e[i].y)==fa&&flag)flag=0;
            else
            {
                if(vis[to])low[s]=min(dfn[to],low[s]);
                else
                {
                    dfs(to,s);sz++;
                    low[s]=min(low[to],low[s]);
                    if(low[to]>=dfn[s])
                    {
                        if(s!=root||sz>1)cut[s]=1;
                        do to=stack2[--sk2],e[to].pdc=e[to^1].pdc=pcnt;
                        while(stack2[sk2]!=i);
                        pcnt++;
                    }
                }
            }
        }
}
void add(int x,int y)
{
    e[mm]=edge(y,0,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}