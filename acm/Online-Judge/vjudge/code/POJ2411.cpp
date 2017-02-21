#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


long long dp[2][1<<11];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        int lim=1<<m;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int l=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                memset(dp[l^1],0,sizeof(dp[l^1]));
                for(int z=0;z<lim;z++)
                {
                    int f=(1<<j-1)|(1<<j);
                    if(((1<<j)&z))
                        dp[l^1][z^(1<<j)]+=dp[l][z];
                    else
                    {
                        if((1<<j-1)&z)
                        dp[l^1][z&((lim-1)^f)]+=dp[l][z],dp[l^1][z|f]+=dp[l][z];
                        else
                            dp[l^1][(z|(1<<j))]+=dp[l][z];
                    }
                }
                memcpy(dp[l],dp[l^1],sizeof(dp[l]));
                l^=1;
            }
        printf("%lld\n",dp[l][0]);
    }
    return 0;
}
