#include <cstdio>
#include <algorithm>
#include <cstring>

#define maxbit (30)
#define mod (1000003LL)
using namespace std;

long long dp[1010][60][2];

int pig[1010];

int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        for (int i=1; i<=n; i++)
            scanf("%d", &pig[i]);
        memset(dp, 0, sizeof(dp));
        for (int k = 1; k<=maxbit; k++)
            dp[0][k][0] = 1LL;

        for (int i=1; i<=n; i++)
            for (int j = i - 1; j>=0; j--)
                for (int k = 1; k<=maxbit; k++)
                {
                    if (pig[i] & (1LL<<(k-1)))
                    {
                        dp[j+1][k][0] = (dp[j+1][k][0] + dp[j][k][1])%mod;
                        dp[j+1][k][1] = (dp[j+1][k][1] + dp[j][k][0])%mod;
                    }
                    else
                    {
                        dp[j+1][k][0] = (dp[j+1][k][0] + dp[j][k][0])%mod;
                        dp[j+1][k][1] = (dp[j+1][k][1] + dp[j][k][1])%mod;
                    }
                }
        /*
        for (int i=1; i<=n; i++)
        {
            for (int j = 0; j<=maxbit; j++)
                printf("%I64d %I64d ", dp[i][j][0], dp[i][j][1]);
            printf("\n");
        }
        */
        for (int i = 1; i<=n; i++)
        {
            long long ans = 0;
            for (int j = 1; j<=maxbit; j++)
                ans = (ans + (1LL<<(j-1)) * dp[i][j][1] ) % mod;
            printf("%I64d%c", ans, (i==n)?'\n':' ');
        }
    }
    return 0;
}
