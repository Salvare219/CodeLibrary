#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define INF 0x7fffffff


int ps[20];
int p,q;
long long mins,maxs;
long long wei[18]; 
void dfs(int now,long long temp)
{
	if(now==p)
	{
		if(temp%(1<<q)==0) 
		{
			if(mins==-1)
			{
				mins=temp;
			}
			else
			{
				maxs=temp;
			}
		}
	}
	else
	{
		dfs(now+1,temp+wei[now]);
		dfs(now+1,temp+2*wei[now]);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	wei[0]=1;
	for(int i=1;i<18;i++)
		wei[i]=wei[i-1]*10;
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&p,&q);
		mins=-1,maxs=-1;
		dfs(0,0);
		if(mins==-1) printf("Case %d: impossible\n",i+1);
		else if(maxs==-1) printf("Case %d: %lld\n",i+1,mins);
		else printf("Case %d: %lld %lld\n",i+1,mins,maxs);
	}
    return 0;
}