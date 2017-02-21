#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;


int num[100006],ans,ans2;
int p[100006];
int n,k;
bool ok(int len)
{
	memset(p,0,sizeof(p));
	int o=0;
	for(int i=0;i<len;i++)
	{
		if(p[num[i]]==0) o++;
		p[num[i]]++;
		if(o==k) 
		{
			ans=1;
			ans2=i+1;
			return 1;
		}
	}
	for(int i=len;i<n;i++)
	{
		p[num[i-len]]--;
		if(p[num[i-len]]==0) o--;
		p[num[i]]++;
		if(p[num[i]]==1) o++;
		if(o==k) 
		{
			ans2=i+1;
			ans=ans2-len+1;
			return 1;
		}
	}
	return 0;
}
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",num+i);
	if(k==1) printf("1 1\n");
	else 
	{
		int sta=1,end=n;
		int mid;
		while(sta<end)
		{
			mid=(sta+end)/2;
			if(ok(mid)) end=mid;
			else sta=mid+1;
		}
		if(end==n) printf("-1 -1\n");
		else printf("%d %d\n",ans,ans2);
	}
	return 0;
}