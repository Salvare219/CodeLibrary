#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char s[100060];
int n;
const int mod=1000000007;
long long T0,T1;
struct bit_tree
{
    long long bit[100060],s;
    inline void updat(long long x,long long v)
    {
        while(x<100005) bit[x]=(bit[x]+v)%mod,x+=x&-x;
    }
    inline long long query(long long x)
    {
        s=0;
        while(x) s=(s+bit[x])%mod,x-=x&-x;
        return s;
    }
}s0,g0,s1,g1;
bool v1[100060];
bool v2[100060];
long long inv1[100060];
long long inv2[100060];
long long con1[100060];
long long con2[100060];
long long sa[100060];


long long G(long long l,long long r)
{
    long long ans=0;
    int cnt=1;
    for(long long i=l;i<=r;i++)
    {
        ans+=cnt*sa[i%n];
        cnt=-cnt;
    }
    return ans;
}
long long cal(long long l,long long r)
{
    long long ans=0;
    for(long long i=l;i<=r;i++)
        for(long long j=i;j<=r;j++)
            ans+=G(i,j);
    return ans;
}



long long cal0(long long b,long long r)
{
    b%=mod;
    long long tim=r/T0%mod,res=r%T0;
    long long A=b*(tim*s0.query(T0)%mod+s0.query(res))%mod;
    long long B=(tim*g0.query(T0)%mod+T0*tim%mod*(tim-1)%mod*s0.query(T0)%mod
                 +g0.query(res)+2*T0*tim%mod*s0.query(res)%mod)%mod;
    return (A-B+mod)%mod;
}
long long cal1(long long b,long long r)
{
    b++;
    b%=mod;
    long long tim=r/T1%mod,res=r%T1;
    long long A=b*(tim*s1.query(T1)%mod+s1.query(res))%mod;
    long long B=(tim*g1.query(T1)%mod+T1*tim%mod*(tim-1)%mod*s1.query(T1)%mod
                 +g1.query(res)+2*T1*tim%mod*s1.query(res)%mod)%mod;
    return (A-B+mod)%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int q;
        scanf("%s%d",s,&q);
        n=strlen(s);
        for(int i=0;i<n;i++)
            sa[i]=s[i]-'0';
        if(n==1)
        {
            while(q--)
            {
                int ty;scanf("%d",&ty);
                if(ty==1)
                {
                    int x,y;
                    scanf("%d%d",&x,&y);
                    sa[x-1]=y;
                }
                else
                {
                    long long l,r,ans=0;
                    scanf("%lld%lld",&l,&r);

                    //printf("%lld  ",cal(l,r));


                    r-=l;
                    long long tim=(r/2+1)%mod;
                    ans=(r%mod-tim+2)*tim%mod;
                    ans=ans*sa[0]%mod;
                    ans=(ans+mod)%mod;
                    printf("%lld\n",ans);
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
                v1[i]=v2[i]=0;
            memset(s0.bit,0,sizeof(long long)*(n+5));
            memset(s1.bit,0,sizeof(long long)*(n+5));
            memset(g0.bit,0,sizeof(long long)*(n+5));
            memset(g1.bit,0,sizeof(long long)*(n+5));
            memset(inv1,-1,sizeof(long long)*(n+5));
            memset(inv2,-1,sizeof(long long)*(n+5));
            T0=T1=0;
            long long sb=0;
            for(int i=0;v1[i]==0;)
            {
                v1[i]=1;T0++;
                inv1[i]=T0;
                con1[i]=sb;
                s0.updat(T0,sa[i]);
                g0.updat(T0,sb*sa[i]%mod);
                sb+=2;
                i+=2;
                if(i>=n)i-=n;
            }
            sb=1;
            for(int i=1;v2[i]==0;)
            {
                v2[i]=1;T1++;
                inv2[i]=T1;
                con2[i]=sb;
                s1.updat(T1,sa[i]);
                g1.updat(T1,sb*sa[i]%mod);
                sb+=2;
                i+=2;
                if(i>=n)i-=n;
            }
            while(q--)
            {
                int ty;scanf("%d",&ty);
                if(ty==1)
                {
                    int x,y;
                    scanf("%d%d",&x,&y);
                    x--;
                    if(inv1[x]!=-1)
                    {
                        s0.updat(inv1[x],-sa[x]);
                        s0.updat(inv1[x],y);

                        g0.updat(inv1[x],-con1[x]*sa[x]);
                        g0.updat(inv1[x],con1[x]*y);
                    }
                    if(inv2[x]!=-1)
                    {
                        s1.updat(inv2[x],-sa[x]);
                        s1.updat(inv2[x],y);

                        g1.updat(inv2[x],-con2[x]*sa[x]);
                        g1.updat(inv2[x],con2[x]*y);
                    }
                    sa[x]=y;
                }
                else
                {
                    long long l,r,ans=0;
                    scanf("%lld%lld",&l,&r);
                    l--;r--;
                    if(l%2==0)
                    {
                        if(n&1)
                        {
                            long long tim=(r+1)/(2*n),res=(r+1)%(2*n);
                            long long cnt=tim*n+(res+1)/2;
                            long long bs=2*cnt-1;
                            if((res&1)==0)bs++;
                            ans+=cal0(bs,cnt);
                            tim=l/(2*n);res=l%(2*n);
                            cnt=tim*n+(res+1)/2;
                            ans-=cal0(bs,cnt);
                        }
                        else ans+=cal0(r+1,r/2+1)-cal0(r+1,l/2);
                    }
                    else
                    {
                        if(n&1)
                        {
                            long long tim=(r+1)/(2*n),res=(r+1)%(2*n);
                            long long cnt=tim*n+res/2;
                            long long bs=2*cnt-1;
                            if(res&1)bs++;
                            ans+=cal1(bs,cnt);
                            tim=l/(2*n);res=l%(2*n);
                            cnt=tim*n+res/2;
                            ans-=cal1(bs,cnt);
                        }
                        else ans+=cal1(r,r/2+1)-cal1(r,l/2);
                    }
                    ans=(ans+mod)%mod;

                    //printf("%lld  ",cal(l,r));

                    printf("%lld\n",ans);
                }
            }
        }
    }
    return 0;
}