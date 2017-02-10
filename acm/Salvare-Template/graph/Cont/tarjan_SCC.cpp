int n,m;
vector<int> gra[2005];
bool vis[2005];        //vis 初始化 0
int stack[2005],sk;
int low[2005],scc[2005];  // scc[i]=j 第 i 个点在第 j 个强连通分量里
int timer,cnt;     //每次调用 cnt 初始化 1 timer 初始化 0 
void tarjan(int s)
{
    vis[s]=1;
    int to,temp=low[s]=++timer;
    stack[sk++]=s;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(vis[to]==0)tarjan(to);
        low[s]=min(low[to],low[s]);
    }
    if(temp==low[s])
    {
        do
        {
            to=stack[--sk];
            low[to]=0x3fffffff;
            scc[to]=cnt;
        }while(stack[sk]!=s);
        cnt++;
    }
}

