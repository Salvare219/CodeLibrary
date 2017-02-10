vector<int>gra[20050];
//判定

int vis[20050];
int dfn[20050],low[20050];
int timer;
bool Cactus(int s)
{
    int y,cnt=0;
    vis[s]=1;
    dfn[s]=low[s]=timer++;
    for(int i=0;i<gra[s].size();i++)
    {
        if(vis[y=gra[s][i]]==2)return 0;
        if(vis[y]==0)
        {
            if(!Cactus(y))return 0;
            if(low[y]>dfn[y])return 0;
            low[s]=min(low[s],low[y]);
        }
        else low[s]=min(low[s],dfn[y]);
        if(low[y]<dfn[s])cnt++;
        if(cnt>1)return 0;
    }
    vis[s]=2;
    return 1;
}