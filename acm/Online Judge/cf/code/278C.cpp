#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



bool vis[200];
int com[200];
int find(int p)
{
	return (com[p]==p)? p:(com[p]=find(com[p]));
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,a,b,c,ans=0,time=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) com[i]=i;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a==0) 
		{
			time++;
			ans++;
		}
		else 
		{
			scanf("%d",&b);
			vis[b]=1;
		}
		for(int j=1;j<a;j++)
		{
			scanf("%d",&c);
			int x=find(b),y=find(c);
			com[y]=x;
			vis[c]=1;
		}
	}
	bool mo[200]={0};
	for(int i=1;i<=m;i++)
	{
		if(vis[i]) 
		{
			a=find(i);
			if(mo[a]==0) 
			{
				mo[a]=1;
				ans++;
			}
		}
	}
	if(time==n) ans++;
	printf("%d\n",ans-1);
	return 0;
}