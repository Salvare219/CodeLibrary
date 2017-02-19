#include<bits/stdc++.h>
using namespace std;


int a[405][405];
int cx[405],cd[405];
int dp[405][10],dpm[405][10];
int to[405];
void rmq(int n)
{
    for(int i=0;i<n;i++)
    {
        dp[i][0]=cx[i];
        dpm[i][0]=cd[i];
    }
    for(int l=2,s=0;l<=n;l<<=1,s++)
        for(int i=0;i+l<=n;i++)
        {
            dp[i][s+1]=min(dp[i][s],dp[i+l/2][s]);
            dpm[i][s+1]=max(dpm[i][s],dpm[i+l/2][s]);
        }
}
void pre_log()
{
    to[1]=0;
    for(int i=2;i<402;i+=2)
        to[i]=to[i+1]=to[i>>1]+1;
}
int query(int l,int r)
{
    int mid=to[r-l+1];
    int len=1<<mid;
    return max(dpm[l][mid],dpm[r-len+1][mid])-min(dp[l][mid],dp[r-len+1][mid]);
}
int main()
{
    //freopen("1.txt","r",stdin);
    pre_log();
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    while(q--)
    {
        long long ans=0;
        int k;scanf("%d",&k);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cx[j]=cd[j]=a[i][j];
            for(int j=i;j<n;j++)
            {
                int t=0;
                for(int z=0;z<m;z++)
                {
                    cx[z]=min(cx[z],a[j][z]);
                    cd[z]=max(cd[z],a[j][z]);
                    if(cd[z]-cx[z]>k)t++;
                }
                if(t==m)
                    break;
                rmq(m);
                int p=-1;
                for(int z=0;z<m;z++)
                {
                    while(p+1<m&&query(z,p+1)<=k)
                        p++;
                    ans+=p-z+1;
                    p=max(p,z);
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
