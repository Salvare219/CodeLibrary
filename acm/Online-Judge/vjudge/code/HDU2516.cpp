#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


long long fib[100];
int main()
{
 //   freopen("1.txt","r",stdin);
	fib[0]=fib[1]=1;
	for(int i=2;i<92;i++)
	{
		fib[i]=fib[i-2]+fib[i-1];
	}
	long long n;
	while(scanf("%lld",&n))
	{
		if(n==0) break;
		bool flag=1;
		for(int i=0;i<92;i++)
			if(n==fib[i])
			{
				flag=0;
				break;
			}
		if(flag) printf("First win\n");
		else printf("Second win\n");
	}
    return 0;
}

