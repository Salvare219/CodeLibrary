#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


const int mod=1000000007;
long long inv[10100500];
long long f[10100500];
long long fac[10100500];
inline long long C(long long n,long long m)
{
    if(n<m)return 0;
    else return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    fac[0]=inv[0]=f[0]=1;
    fac[1]=inv[1]=f[1]=1;
    for(int i=2;i<10100005;i++)
    {
        f[i]=(-mod/i)*f[mod%i]%mod;
        if(f[i]<0)f[i]+=mod;
        inv[i]=inv[i-1]*f[i]%mod;
        fac[i]=fac[i-1]*i%mod;
    }
    while(t--)
    {
        long long b,g,m,ans=0;scanf("%lld%lld%lld",&b,&g,&m);
        for(int i=0;i<=g;i++)
        {
            long long te=C(g,i)*C(b-i*(m+1)+g-1,g-1)%mod;
            if(te==0)break;
            if(i&1) ans=(ans-te)%mod;
            else ans=(ans+te)%mod;
        }
        printf("%lld\n",(ans+mod)%mod);
    }
    return 0;
}
