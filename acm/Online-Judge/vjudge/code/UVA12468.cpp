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


int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b))
	{
		int temp;
		if(a==-1 && b==-1) break;
		if(a>b) 
		{
			temp=a;
			a=b;
			b=temp;
		}
		int m=b-a;
		int n=100-m;
		printf("%d\n",min(n,m));
	}
    return 0;
}