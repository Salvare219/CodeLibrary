#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
  
long long gcd(long long a,long long b)
{
	long long c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
		long long n,a;
		scanf("%I64d",&n);
		a=gcd(4*n,n+1);
		printf("%I64d \n",4*n/a+1);
	}
    return 0;
}