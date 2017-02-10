//标号 0 开始 全局最小割
int cap[505][505];
int node[505],dis[505];
int Stoer_Wagner(int n)
{
    int i,j,now,ans=0x3fffffff;
    for(int i=0;i<n;i++) node[i]=i;
    while(n>1)
    {
        for(now=0,i=1;i<n;i++) dis[node[i]]=0;
        for(i=1;i<n;i++)
        {
            swap(node[now],node[i-1]);
            for(now=j=i;j<n;j++)
            {
                dis[node[j]]+=cap[node[i-1]][node[j]];
                if(dis[node[now]]<dis[node[j]]) now=j;
            }
        }
        ans=min(ans,dis[node[now]]);
        for(j=0;j<n;j++)
            cap[node[j]][node[now-1]]=cap[node[now-1]][node[j]]+=cap[node[j]][node[now]];
        node[now]=node[--n];
    }
    return ans;
}