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
#define INF 0x7fffffff


int num[500005],temp[500005];
long long ans;
void pai(int sta,int end)
{
	int s=sta,e=end-1,con=0;
	for(int i=end-1;i>sta;i--)
	{
		if(num[i]>num[sta]) 
		{
			temp[e--]=num[i];
			ans+=con;
		}
		else 
		{
			temp[s++]=num[i];
			con++;
		}
	}
	ans+=con;
	temp[e]=num[sta];
	for(int i=sta;i<e;i++)
		num[i]=temp[e-i+sta-1];
	for(int i=e;i<end;i++)
		num[i]=temp[i];
	if(end-e>2) pai(e+1,end);
	if(e-sta>1) pai(sta,e);
}
int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		ans=0;
		for(int i=0;i<n;i++)
			scanf("%d",num+i);
		pai(0,n);
		printf("%lld\n",ans);
	}
	return 0;
}