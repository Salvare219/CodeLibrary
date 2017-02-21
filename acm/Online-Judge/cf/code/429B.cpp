#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[1005][1005];
int dp1[1005][1005][2];
int dp2[1005][1005][2];
int dp3[1005][1005][2];
int dp4[1005][1005][2];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp1[i][j][0]=max(dp1[i-1][j][0],dp1[i-1][j][1])+a[i][j];
            dp1[i][j][1]=max(dp1[i][j-1][0],dp1[i][j-1][1])+a[i][j];
        }
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
        {
            dp2[i][j][0]=max(dp2[i+1][j][0],dp2[i+1][j][1])+a[i][j];
            dp2[i][j][1]=max(dp2[i][j-1][0],dp2[i][j-1][1])+a[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
        {
            dp3[i][j][0]=max(dp3[i-1][j][0],dp3[i-1][j][1])+a[i][j];
            dp3[i][j][1]=max(dp3[i][j+1][0],dp3[i][j+1][1])+a[i][j];
        }
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
        {
            dp4[i][j][0]=max(dp4[i+1][j][0],dp4[i+1][j][1])+a[i][j];
            dp4[i][j][1]=max(dp4[i][j+1][0],dp4[i][j+1][1])+a[i][j];
        }
    int ans=0;//dasda
    for(int i=2;i<=n-1;i++)
        for(int j=2;j<=m-1;j++)
        {
            int d1=dp1[i][j][0]-a[i][j]+dp2[i][j][1]-a[i][j];
            int d2=dp1[i][j][1]-a[i][j]+dp2[i][j][0]-a[i][j];
            int d3=dp1[i][j][1]-a[i][j]+dp2[i][j][1]-a[i][j];
            int d4=dp3[i][j][0]-a[i][j]+dp4[i][j][1]-a[i][j];
            int d5=dp3[i][j][1]-a[i][j]+dp4[i][j][0]-a[i][j];
            int d6=dp3[i][j][1]-a[i][j]+dp4[i][j][1]-a[i][j];
            int len1=d1+d5;
            int len2=d2+d4;
            ans=max(ans,max(len1,len2));
        }
    printf("%d\n",ans);
    return 0;
}

