#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


bool vis[1300032];
long long prim[70005],pk;
long long dp[105],dp2[105];
void cal()
{
    for(int i=2;pk<70001;i++)
    {
        if(vis[i]==0) prim[pk++]=i;
        for(int j=0;j<pk && prim[j]*i<1300031;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }
}
inline long long pow_mod(long long a,long long b,int mod)
{
    long long c=1;
    while(b)
    {
        if(b&1) c=(c*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return c;
}
int main()
{
	long long n,c;
	int l;
	cal();
	while(scanf("%I64d%I64d%d",&n,&c,&l)==3)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        long long mod=1;
        for(int i=0;i<l;i++) mod*=10;
        for(int i=0;i<n;i++)
        {
            long long res=pow_mod(prim[i],prim[i],c);
            memset(dp2,0,sizeof(dp2));
            for(int j=0;j<c;j++)
                dp2[(j+res)%c]=(dp2[(j+res)%c]+dp[j])%mod;
            for(int j=0;j<c;j++)
                dp2[j]=(dp2[j]+dp[j])%mod;
            memcpy(dp,dp2,sizeof(dp));
        }
        printf("%0*I64d\n",l,(dp[0]-1+mod)%mod);
    }
	return 0;
}
