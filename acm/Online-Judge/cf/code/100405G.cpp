#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long gcd(long long a,long long b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    long long a,b,c;
    while(~scanf("%I64d%I64d%I64d",&a,&b,&c))
    {
        long long d=a*b,e=c-b;
        long long g=gcd(d,e);
        printf("%I64d/%I64d\n",d/g,e/g);
    }
	return 0;
}
