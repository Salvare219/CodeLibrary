#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dp[2500][70],dp2[2500][70];
int C[2050][2050];
long long fac[2005];
const int mod=1000000007;
void cal()
{
    dp[0][0]=1;
    for(int i=1;i<1002;i++)
    {
        memset(dp2,0,sizeof(dp2));
        for(int j=0;j<60;j++)
        {
            for(int k=0;k<=1005;k++)
            {
                dp2[k+i][j+1]+=dp[k][j];
                if(dp2[k+i][j+1]>=mod)dp2[k+i][j+1]-=mod;
                dp2[k][j]+=dp[k][j];
                if(dp2[k][j]>=mod)dp2[k][j]-=mod;
            }
        }
        memcpy(dp,dp2,sizeof(dp));
    }
    fac[0]=1;
    for(int i=1;i<2003;i++)
        fac[i]=(fac[i-1]*i)%mod;
    for(int i=0;i<2005;i++)C[i][0]=1;
    for(int i=1;i<2005;i++)
        for(int j=1;j<=i;j++)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod)C[i][j]-=mod;
        }
    for(int i=1;i<2005;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=C[i][j]*fac[j]%mod;
}
int main()
{
    int t;scanf("%d",&t);
    cal();
    while(t--)
    {
        int n,k;
        int ans=0;
        scanf("%d%d",&n,&k);
        if(k>58)puts("0");
        else
        {
            for(int i=0;i<=n;i++)
            {
                ans+=1ll*dp[i][k]*C[n-i+k][k]%mod;
                if(ans>=mod)ans-=mod;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
