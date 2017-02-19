#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


const int mod=1000000007;
int dp[1<<20];
int pow_mod(long long a,int b)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=c*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&x),dp[x]++;
    for(int i=0;i<20;i++)
        for(int j=0;j<(1<<20);j++)
            if((1<<i)&j)dp[(1<<i)^j]+=dp[j];
    long long ans=0;
    for(int i=0;i<(1<<20);i++)
    {
        int cnt=0;
        for(int j=0;j<20;j++)
            if((1<<j)&i)cnt++;
        if(cnt&1)ans=(ans-pow_mod(2,dp[i]))%mod;
        else ans=(ans+pow_mod(2,dp[i]))%mod;
    }
    printf("%I64d\n",(ans+mod)%mod);
    return 0;
}
