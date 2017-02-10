// O(n^2)
int e[105][105],cir[105][105]; //e初始化无穷 cir初始化0
int dis[105],ind[105],pre[105];
bool use[105][105];
void SEC_MST(int n)
{
    int temp,f,ans=0,ans2=0x3fffffff;
    for(int i=0;i<n;i++)
        dis[i]=e[0][i],ind[i]=i,pre[i]=0;
    for(int i=1;i<n;i++)
    {
        f=i;temp=dis[ind[i]];
        for(int j=i+1;j<n;j++)
            if(dis[ind[j]]<temp)
                f=j,temp=dis[ind[j]];
        swap(ind[f],ind[i]);f=ind[i];
        use[f][pre[f]]=use[pre[f]][f]=1;
        for(int j=0;j<i;j++)
            cir[f][ind[j]]=cir[ind[j]][f]=max(e[f][pre[f]],cir[ind[j]][pre[f]]);
        ans+=dis[f];
        for(int j=i+1;j<n;j++)
            if(dis[ind[j]]>e[f][ind[j]]) dis[ind[j]]=e[f][ind[j]],pre[ind[j]]=f;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(use[i][j]==0)
                ans2=min(ans2,e[i][j]-cir[i][j]);
}