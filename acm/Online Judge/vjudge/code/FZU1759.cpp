#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char bb[1000005];
inline long long phi(long long n)
{
	long long ret=1;
	for(long long i=2;i*i<=n;i++)
		if(n%i==0)
		{
			n/=i,ret*=i-1;
			while(n%i==0) n/=i,ret*=i;
		}
    if(n>1) ret*=n-1;
    return ret;
}
inline long long pow_mod(long long a,long long b,long long mod)
{
    long long c=1,d=a%mod;
    while(b)
    {
        if(b&1) c=(c*d)%mod;
        b>>=1;
        d=(d*d)%mod;
    }
    return c;
}
bool cmp(long long s)
{
    int i=0;
    long long f=0;
    while(bb[i])
    {
        f=f*10+bb[i]-'0';
        i++;
        if(f>s) return 1;
    }
    return 0;
}
long long toint()
{
    int i=0;
    long long f=0;
    while(bb[i])
        f=f*10+bb[i++]-'0';
    return f;
}
long long mod(long long s)
{
    int i=0;
    long long f=0;
    while(bb[i]) f=(f*10+bb[i++]-'0')%s;
    return f;
}
int main()
{
	long long a,d,c;
	while(scanf("%I64d%s%I64d",&a,bb,&c)==3)
    {
        long long s=phi(c);
        if(cmp(s)) d=mod(s)+s;
        else d=toint();
        printf("%I64d\n",pow_mod(a,d,c));
    }
	return 0;
}