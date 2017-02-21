#include <bits/stdc++.h>
using namespace std;


long long k,mod;
long long pow_mod(long long a,long long b)
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
long long cal(long long k)
{
    if(k<=1)return k%mod;
    long long s=cal(k/2);
    if(k&1)
        return (s+(s*10+1)%mod*pow_mod(10,k/2)%mod)%mod;
    else
        return (s+s*pow_mod(10,k/2))%mod;
}
int main()
{
    freopen("zeroes.in","r",stdin);
    freopen("zeroes.out","w",stdout);
    scanf("%lld%lld",&k,&mod);
    long long s1=k%mod+(k-1)%mod*pow_mod(10,k-1)%mod;
    long long s2=cal(k-1);
    long long s3=((s1-s2)%mod+mod)%mod;
    printf("%lld\n",s3);
    return 0;
}
