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


int num[2006],temp[2008];
bool cmpda(int a,int b)
{
	return a<b;
}
bool cmpx(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",num+i);
		temp[i]=num[i];
	}
	sort(num,num+m,cmpda);
	long long ansx=0,ansd=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		while(num[k]==0) k++;
		ansx+=num[k];
		num[k]--;
	}
	for(int i=0;i<n;i++)
	{
		sort(temp,temp+m,cmpx);
		ansd+=temp[0];
		temp[0]--;
	}
	printf("%I64d %I64d\n",ansd,ansx);
    return 0;
}