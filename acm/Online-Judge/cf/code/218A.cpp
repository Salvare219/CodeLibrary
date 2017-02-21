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


int num[2006];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	n=2*n+1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	for(int i=1;i<n;i+=2)
	{
		if(num[i]-1>num[i-1] && num[i]-1>num[i+1])
		{
			k--;
			num[i]--;
		}
		if(k==0) break;
	}
	printf("%d",num[0]);
	for(int i=1;i<n;i++)
		printf(" %d",num[i]);
	putchar(10);
    return 0;
}