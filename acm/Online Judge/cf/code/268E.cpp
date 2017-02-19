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



struct ps
{
	long long e,p;
}ef[100000];
bool cmp(struct ps a,struct ps b)
{
	return a.e*(100-b.p)>b.e*(100-a.p);
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,x,y;
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		sum+=x;
		ef[i].e=x*y;
		ef[i].p=y;
	}
	sort(ef,ef+n,cmp);
	long long ans=0;
	for(int i=0;i<n-1;i++)
	{
		ans=ans+ef[i].e*(100-ef[i+1].p);
		ef[i+1].e=ef[i+1].e+ef[i].e;
	}
	printf("%lf\n",1.0*ans/10000+sum);
	return 0;
}