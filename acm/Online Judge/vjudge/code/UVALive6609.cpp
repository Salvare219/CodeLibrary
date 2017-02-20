#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long num[500005],n;
long long dp[500005][30];
void rmq()
{
	for(int i=0;i<n;i++)dp[i][0]=num[i];
	for(int l=2,s=0;l<=n;l<<=1,s++)
        for(int i=0;i+l<=n;i++)
			dp[i][s+1]=max(dp[i][s],dp[i+l/2][s]);
}
int to[500008];
void pre_log()
{
    to[1]=0;
    for(int i=2;i<500004;i+=2)
        to[i]=to[i+1]=to[i>>1]+1;
}
long long query(int l,int r)
{
    if(l>r) swap(l,r);
    int mid=to[r-l+1];
    int len=1<<mid;
    return max(dp[l][mid],dp[r-len+1][mid]);
}
int main()
{
    pre_log();
    int t;scanf("%d",&t);
    while(t--)
    {
        int x,k;
        scanf("%d%d",&n,&k);num[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&x),num[i]=x+num[i-1];
        num[n+1]=0x3fffffff;
        num[n+1]*=num[n+1];
        n+=2;rmq();n--;
        int l,r,mid,ans=n+5;
        for(int i=0;i<n;i++)
        {
            l=i;r=n;
            while(l<r)
            {
                mid=(l+r)>>1;
                if(query(i,mid)-num[i]>=k)r=mid;
                else l=mid+1;
            }
            if(i!=r)
            {
                if(r!=n)ans=min(ans,r-i);
            }
        }
        if(ans<n+5)printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}