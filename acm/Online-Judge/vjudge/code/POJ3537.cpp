#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int sg[2005];
int dfs(int n)
{
	if(sg[n]!=-1) return sg[n];
	bool vis[2050]={0};
	int x,y,i;
	for(i=1;i<=n;i++)
	{
		x=max(i-3,0);
		y=max(n-i-2,0);
		vis[dfs(x)^dfs(y)]=1;
	}
	i=0;
	while(vis[i]) i++;
	return sg[n]=i;
}
int main()
{
//	freopen("1.txt","r",stdin);
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n%2) printf("1\n");
		else 
		{
			if(dfs(n)) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}