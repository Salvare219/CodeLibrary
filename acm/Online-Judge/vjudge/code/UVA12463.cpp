#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
#define INF 0x7fffffff
#define mod 1000000009


int main()
{
	int a,b,c,d,e;
	while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&e))
	{
		if(a==0 && b==0 && c==0 && d==0 && e==0) break;
		long long sum=(long long)a*b*c*d*d*e*e;
		printf("%lld\n",sum);
	}
    return 0;
}