//适合增广路长或费用范围大的图
Ver 3.0  支持重边
struct edge
{
    int y,c,f,next;
    edge(){}
    edge(int y_,int c_,int f_,int n_){y=y_,c=c_,f=f_,next=n_;}
}e[2007000];
int head[2005];
int nn,mm;
int q[2005],p[2005],dis[2005];
bool vis[2005];
bool spfa(int s,int t)
{
    int to,tail=1,front=0;
    for(int i=1;i<=nn;i++) vis[i]=0,dis[i]=0x3fffffff;
    dis[s]=0;q[0]=s;
    while(tail!=front)
    {
        s=q[front++];vis[s]=0;
        if(front>nn)front=0;
        for(int i=head[s];~i;i=e[i].next)
            if(e[i].c&&dis[to=e[i].y]>dis[s]+e[i].f)
            {
                dis[to]=dis[s]+e[i].f;p[to]=i^1;
                if(vis[to]==0)
                {
                    vis[to]=1;
                    if(dis[to]<dis[q[front]])
                        front==0?front=nn:front--,q[front]=to;
                    else
                        q[tail++]=to,tail>nn?tail=0:0;
                }
            }
    }
    if(dis[t]<0x3fffffff) return 1;
    else return 0;
}
int cost_flow(int s,int t)
{
	int ans=0,flow,x;
	while(spfa(s,t))
	{
	    flow=0x3fffffff;
		for(x=t;x!=s;x=e[p[x]].y) flow=min(flow,e[p[x]^1].c);
		for(x=t;x!=s;x=e[p[x]].y)
			e[p[x]].c+=flow,e[p[x]^1].c-=flow,ans+=flow*e[p[x]^1].f;
	}
	return ans;
}
inline void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}

