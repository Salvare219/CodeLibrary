// tanjar 离线算法
void dfs(int s,int p)
{
    int x;
    for(int i=0;i<gra[s].size();i++)
        if((x=gra[s][i])!=p)dfs(x,s),com[x]=s;
    vis[s]=1;
    for(int i=0;i<q[s].size();i++)
        if(vis[x=q[s][i]]) ans[id[s][i]]=find(x);
}

//倍增 标号 1 开始  根节点 深度设为 1
// pre 数组初始化！！！
//预处理  
int pre[50050][20];
int dep[50050];
void dfs(int s,int p)
{
    int t=0;
    pre[s][0]=p;
    while(pre[s][t]) pre[s][t+1]=pre[pre[s][t]][t],t++;
    for(int i=0;i<gra[s].size();i++)
        if((t=gra[s][i])!=p)
        {
            dep[t]=dep[s]+1;
            dfs(t,s);
        }
}
int lca(int x,int y)
{
    int s=19;
    if(dep[x]>dep[y]) swap(x,y);
    while(dep[x]<dep[y]) y=dep[pre[y][s]]<dep[x]?y:pre[y][s],s--;
    if(x==y) return x;
    else
    {
        s=19;
        while(s!=-1)
        {
            if(pre[x][s]!=pre[y][s])
                x=pre[x][s],y=pre[y][s];
            s--;
        }
        return pre[x][0];
    }
}
