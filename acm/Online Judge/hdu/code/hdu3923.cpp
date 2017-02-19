#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int mod=1000000007;
long long pow_mod(int a,int b)
{
    long long c=1,d=a%mod;
    while(b)
    {
        if(b&1)c=(c*d)%mod;
        b>>=1;d=(d*d)%mod;
    }
    return c;
}
int gcd(int a,int b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    int c,s,t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&c,&s);
        long long ans=0;
        for(int i=1;i<=s;i++)
            ans=(ans+pow_mod(c,gcd(s,i)))%mod;
        if(s&1)ans=(ans+s*pow_mod(c,s/2+1))%mod;
        else ans=(ans+s/2*(pow_mod(c,s/2+1)+pow_mod(c,s/2)))%mod;
        printf("Case #%d: %I64d\n",ti++,ans*pow_mod(s<<1,mod-2)%mod);
    }
    return 0;
}
