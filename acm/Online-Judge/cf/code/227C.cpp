#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<ctime>
using namespace std;



int pow_mod(int n,int mod)
{
	long long a=3,b=1;
	while(n)
	{
		if(n%2) b=(a*b)%mod;
		n/=2;
		a=(a*a)%mod;
	}
	return b;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",(pow_mod(n,m)+m-1)%m);
    return 0;
}