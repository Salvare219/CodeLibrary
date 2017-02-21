#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dp[305][305],dp2[305][305],dp3[305][305];
int a[400][400],b[400][400];
int dx[]={1,1,0,0},dy[]={0,1,0,1};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=-1000000;
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp2[i][j]=-1000000;
        for(int j=0;j<i;j++)
            for(int k=j;k<i;k++)
            {
                for(int c=0;c<4;c++)
                {
                    int x1=j+dx[c],y1=k+dy[c];
                    if(x1>y1)swap(x1,y1);
                    if(x1!=y1)
                    dp2[x1][y1]=max(dp2[x1][y1],dp[j][k]+a[i-x1][x1]+a[i-y1][y1]);
                    else
                    dp2[x1][y1]=max(dp2[x1][y1],dp[j][k]+a[i-x1][x1]);
                }
            }
        memcpy(dp,dp2,sizeof(dp));
    }
    memcpy(dp3,dp,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            b[n-j-1][n-1-i]=a[i][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=-1000000;
    dp[0][0]=b[0][0];
    for(int i=1;i<n;i++)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp2[i][j]=-1000000;
        for(int j=0;j<=i;j++)
            for(int k=j;k<=i;k++)
            {
                for(int c=0;c<4;c++)
                {
                    int x1=j+dx[c],y1=k+dy[c];
                    if(x1!=y1)
                    dp2[x1][y1]=max(dp2[x1][y1],dp[j][k]+b[i-x1][x1]+b[i-y1][y1]);
                    else
                    dp2[x1][y1]=max(dp2[x1][y1],dp[j][k]+b[i-x1][x1]);
                }
            }
        memcpy(dp,dp2,sizeof(dp));
    }
    int ans=-10000000;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(i!=j)
            ans=max(ans,dp[i][j]+dp3[i][j]-a[n-i-1][i]-a[n-j-1][j]);
            else
            ans=max(ans,dp[i][j]+dp3[i][j]-a[n-i-1][i]);
    printf("%d\n",ans);
	return 0;
}