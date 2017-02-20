#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


unsigned long long pow_mult(unsigned long long a,unsigned long long b,unsigned long long mod)
{
    unsigned long long c=0;
    while(b)
    {
        if(b&1)
        {
            c+=a;
            if(c>=mod) c-=mod;
        }
        a<<=1;
        if(a>=mod) a-=mod;
        b>>=1;
    }
    return c;
}
unsigned long long pow_mod(unsigned long long a,unsigned long long b,unsigned long long mod)
{
    a%=mod;
    unsigned long long c=1;
    while(b)
    {
        if(b&1) c=pow_mult(c,a,mod);
        b>>=1;
        a=pow_mult(a,a,mod);
    }
    return c;
}
int main()
{
//	freopen("1.txt","r",stdin);
    long long a,b,c;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)==3)
        printf("%I64d\n",pow_mod(a,b,c));
	return 0;
}
