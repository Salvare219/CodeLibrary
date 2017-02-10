//割点 & 桥
vector<int>gra[10005];
bool v[10005],cut[10005];  //初始化全 0
int low[10005],dfn[10005];
int timer,root;   //timer=1  root 初始化
void dfs(int s,int p)
{
    bool f=1;
    int y,cnt=0;
    v[s]=1;
    dfn[s]=low[s]=timer++;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])==p&&f)f=0;
        else
        {
            if(v[y])low[s]=min(low[s],dfn[y]);
            else
            {
                dfs(y,s);cnt++;
                low[s]=min(low[s],low[y]);
                if((s!=root&&low[y]>=dfn[s])||(s==root&&cnt>1))cut[s]=1;
                if(low[y]>dfn[s])
                {
                    //bri[0].push_back(s);
                    //bri[1].push_back(y);
                }
            }
        }
    if(low[s]==dfn[s])
    {
        int h;
        do
        {
            h=stack[--k];
            col[h]=cnt;
        }while(stack[k]!=s);
        cnt++;
    }
}