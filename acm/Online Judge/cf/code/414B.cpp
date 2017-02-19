#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dp[2050][2050];
const int mod=1000000007;
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    dp[0][1]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            for(int z=j;z<=n;z+=j)
            {
                dp[i][z]+=dp[i-1][j];
                if(dp[i][z]>=mod)dp[i][z]-=mod;
            }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+dp[k][i])%mod;
    printf("%d\n",ans);
    return 0;
}
