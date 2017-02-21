#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

int kk=1<<31;
long long pow_mult(long long a,long long b,long long mod)
{
    a%=mod;b%=mod;
    if(a<kk && b<kk) return a*b%mod;
    long long c=0;
    while(b)
    {
        if(b&1)
        {
            c=c+a;
            if(c>=mod) c-=mod;
        }
        b>>=1;
        a<<=1;
        if(a>=mod) a-=mod;
    }
    return c;
}
long long pow_mod(long long a,long long b,long long mod)
{
    a%=mod;
    long long c=1;
    while(b)
    {
        if(b&1) c=pow_mult(c,a,mod);
        b>>=1;
        a=pow_mult(a,a,mod);
    }
    return c;
}
long long gcd(long long a,long long b)
{
    long long c=a%b;
    while(c)
    {
        a=b;b=c;
        c=a%b;
    }
    return b;
}
long long pollard_rho(long long n)
{
    if(n==2) return 0;
    if((n&1)==0) return 2;
    long long d,x1,x2;
    for(int i=1;i<100;i++)
    {
        x1=rand()%n;
        x2=(pow_mult(x1,x1,n)+n-1)%n;
        d=gcd((x2+n-x1)%n,n);
        while(d==1)
        {
            x1=(pow_mult(x1,x1,n)+n-1)%n;
            x2=(pow_mult(x2,x2,n)+n-1)%n;
            x2=(pow_mult(x2,x2,n)+n-1)%n;
            d=gcd((x2+n-x1)%n,n)%n;
        }
        if(d) return d;
    }
    return 0;
}
bool miller_rabin(long long n)
{
    if(n==1) return 1;
    long long u,x1,x2;
    int t;
    for(int i=0;i<3;i++)
    {
        long long a=rand()%(n-1)+1;
        u=n-1;t=0;
        while(u%2==0) u>>=1,t++;
        x1=pow_mod(a,u,n);
        for(int i=0;i<t;i++)
        {
            x2=pow_mult(x1,x1,n);
            if(x2==1 && x1!=1 && x1!=n-1) return 0;
            x1=x2;
        }
        if(x1!=1) return 0;
    }
    return 1;
}
long long prim(long long n)
{
    if(miller_rabin(n)) return n;
    return prim(pollard_rho(n));
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,fin,temp,m;
        scanf("%lld",&n);
        m=fin=n;
        for(int i=0;i<10 && n!=1;i++)
        {
            temp=prim(n);
            n/=temp;
            if(fin>temp) fin=temp;
        }
        if(fin!=m) printf("%lld\n",fin);
        else printf("Prime\n");
    }
    return 0;
}
