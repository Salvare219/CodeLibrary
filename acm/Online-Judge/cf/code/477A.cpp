#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


const int mod=1000000007;
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
int main()
{
    //freopen("1.txt","r",stdin);
    long long a,b,ans=0;
    scanf("%I64d%I64d",&a,&b);
    long long inv=pow_mod(2,mod-2);
    for(int i=1;i<b;i++)
    {
        long long c=i,d=i*a%mod;
        ans=(ans+(c*b%mod+i+d*b%mod+i)%mod*a%mod*inv%mod)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}