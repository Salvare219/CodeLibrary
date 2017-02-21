#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


long long sum[1001][1001],dp[1001][1001];
int a[1001][1001];
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
	    int x;
	    memset(a,0,sizeof(a));
	    memset(sum,0,sizeof(sum));
	    for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                scanf("%d",&a[i-j+1][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n-i+1;j++)
                sum[i][j]=sum[i][j-1]+a[i][j];
        long long te;
        for(int i=1;i<=n;i++)
        {
            te=dp[i-1][n-i+2];
            for(int j=n-i+1;j>0;j--)
            {
                te=max(te,dp[i-1][j]);
                dp[i][j]=te+sum[i][j];
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n-i+1;j++)
                ans=max(ans,dp[i][j]);
		printf("%lld\n",ans);
	}
	return 0;
}
