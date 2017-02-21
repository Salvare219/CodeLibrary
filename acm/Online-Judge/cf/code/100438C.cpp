#include<bits/stdc++.h>
using namespace std;


const int mod=1000000007;
long long c[1<<15],cnt[1<<15];
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
long long cal(int s,int k)
{
    long long h=1,sum=0;
    for(int i=0;i<k;i++)
    {
        sum=(sum+h)%mod;
        h=h*s%mod;
    }
    return sum;
}
long long pi[1<<15];
long long pk[1<<15];
int n;
long long fz[1<<15];
long long fg[1<<15];
long long cz[1<<15];
long long cg[1<<15];

int main()
{

    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        long long sb=1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int pp=1<<i;
            scanf("%I64d%I64d",&c[pp],&cnt[pp]);
            for(int j=0;j<cnt[pp];j++)
                sb=sb*c[pp]%mod;
        }
        for(int i=0;i<n;i++)
        {
            int pp=1<<i;
            pk[pp]=cal(c[pp],cnt[pp])%mod;
            pi[pp]=cal(c[pp],cnt[pp]+1)%mod;
        }
        int lim=1<<n;
        fz[0]=fg[0]=cz[0]=cg[0]=1;
        for(int i=1;i<lim;i++)
        {
            int pp=1<<(31-__builtin_clz(i));
            fz[i]=pk[pp]*fz[i^pp]%mod;
            fg[i]=pi[pp]*fg[i^pp]%mod;
            cz[i]=cnt[pp]*cz[i^pp]%mod;
            cg[i]=(cnt[pp]+1)*cg[i^pp]%mod;
        }
        long long ans=0;
        for(int i=0;i<lim;i++)
        {
            long long sum;
            long long pp;
            int f=__builtin_popcount(i);
            sum=fz[i]*fg[(lim-1)^i]%mod;
            pp=cz[i]*cg[(lim-1)^i]%mod;
            /*
            for(int j=0;j<n;j++)
                if((1<<j)&i)
                {
                    f++;
                    sum=pk[j]*sum%mod;
                    pp=cnt[j]*pp%mod;
                }
                else
                {
                    sum=pi[j]*sum%mod;
                    pp=(cnt[j]+1)*pp%mod;
                }*/
            long long ff=sum*pp%mod;
            ff=2*ff%mod;
            if(f&1)
                ans=(ans-ff)%mod;
            else
                ans=(ans+ff)%mod;
        }
        ans=(ans-sb-sb)%mod;
        ans=ans*pow_mod(2,mod-2)%mod;
        ans=(ans+sb+sb)%mod;
        ans=(ans+mod)%mod;
        printf("Case %d: %I64d\n",ti++,ans);
    }
    return 0;
}
