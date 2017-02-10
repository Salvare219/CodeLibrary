//O(m*logm+k*m)  要求某个点度数小于或等于 k
#define INF 0x3fffffff
struct edge
{
    int x,y,w;
    bool operator<(const edge a)const
    {return w<a.w;}
}e[450];
int n,m;
int dis[25][25],temp[25];
int com[25],con[25];
int find(int s){return s==com[s]?s:com[s]=find(com[s]);}
int dfs(int s,int p,int x,int y)
{
    if(con[s]<INF)
    {
        if(temp[0]>con[s]-dis[x][y])
            temp[0]=con[s]-dis[x][y],temp[1]=x,temp[2]=y,temp[3]=s;
    }
    for(int i=0;i<n;i++)
        if(dis[i][s]<INF && i!=p)
        {
            if(dis[x][y]<dis[i][s]) dfs(i,s,s,i);
            else dfs(i,s,x,y);
        }
    return 0;
}
int K_MST(int root,int k)
{
    int x,y,z=n-1,s=0,ans=0;
    sort(e,e+m);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dis[i][j]=INF;
    for(int i=0;i<n;i++)
        com[i]=i,temp[i]=-1,con[i]=INF;
    for(int i=0;i<m;i++)
        if(e[i].x!=root && e[i].y!=root)
        {
            x=find(e[i].x),y=find(e[i].y);
            if(x!=y)
            {
                if(x>y) swap(x,y);
                com[x]=y;ans+=e[i].w;z--;
                dis[e[i].x][e[i].y]=dis[e[i].y][e[i].x]=e[i].w;
            }
        }
        else
        {
            x=e[i].x==root?e[i].y:e[i].x;
            con[x]=min(con[x],e[i].w);
        }
    for(int i=0;i<n;i++)
        if(i!=root)
        {
            x=find(i);
            if(temp[x]==-1) temp[x]=i;
            else temp[x]=con[i]<con[temp[x]]?i:temp[x];
            if(x==i)
            {
                if(con[temp[x]]!=INF)
                    dis[temp[x]][root]=dis[root][temp[x]]=con[temp[x]],ans+=con[temp[x]],s++;
            }
        }
    if(z>s || s>k) return -1;
    for(int i=s;i<k;i++)
    {
        temp[0]=INF;
        for(int j=0;j<n;j++)
            if(dis[root][j]<INF) dfs(j,root,root,j);
        if(temp[0]>=0) break;
        dis[root][temp[3]]=dis[temp[3]][root]=con[temp[3]];
        dis[temp[1]][temp[2]]=dis[temp[2]][temp[1]]=INF;ans+=temp[0];
    }
    return ans;
}