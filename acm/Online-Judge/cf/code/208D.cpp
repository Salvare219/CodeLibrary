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


long long num[100];
long long pri[10];
long long con[10]={0};
bool cmp(long long a,long long b)
{
	return a<b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%I64d",num+i);
	for(int i=0;i<5;i++)
		scanf("%I64d",pri+i);
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=num[i];
		for(int j=4;j>-1;j--)
		{
			con[j]=con[j]+sum/pri[j];
			sum=sum%pri[j];
		}
	}
	printf("%I64d",con[0]);
	for(int i=1;i<5;i++)
		printf(" %I64d",con[i]);
	printf("\n%I64d\n",sum);
    return 0;
}