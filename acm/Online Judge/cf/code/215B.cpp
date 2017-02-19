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
	int mx[2]={0,1};
	int n,m,k;
	scanf("%d",&n);
	int maxx=-1,minx=0x7fffffff,ppp=-1;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp>maxx) maxx=temp;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(temp>ppp) ppp=temp;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int temp;
		scanf("%d",&temp);
		if(minx>temp) minx=temp;
	}
	int A,B;
	scanf("%d%d",&A,&B);
	double pppp=ppp;
	printf("%.12lf\n",maxx*sqrt((B*pppp)/(B*pppp+A*minx)));
    return 0;
}