#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


const int mod=1000000007;
int a[2050],v[2050];
long long fac[2050],inv[2050];
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
long long C(int n,int m)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    int n;scanf("%d",&n);
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=pow_mod(fac[i],mod-2);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        if(a[i]!=-1)v[a[i]]=1;
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++)
        if(v[i]==0)
        {
            if(a[i]!=-1)
                x++;
            else
                y++;
        }
    long long ans=0;
    for(int i=0;i<=y;i++)
        if(i&1)
            ans=(ans-C(y,i)*fac[x+y-i]%mod)%mod;
        else
            ans=(ans+C(y,i)*fac[x+y-i]%mod)%mod;
    printf("%d\n",(int)(ans+mod)%mod);
    return 0;
}
