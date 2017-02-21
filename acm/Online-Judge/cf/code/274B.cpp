#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



vector<int> gra[100005];
int num[100005];
void dfs(int now,int fa,long long &x,long long &y)
{
	for(int i=0;i<gra[now].size();i++)
	{
		long long a=0,b=0;
		if(gra[now][i]==fa) continue;
		dfs(gra[now][i],now,a,b);
		x=max(x,a);
		y=max(y,b);
	}
	long long temp=num[now]+x-y;
	if(temp>0) y+=temp;
	else x-=temp;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n;
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		gra[x].push_back(y);
		gra[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i+1]);
	}
	long long pl=0,de=0;
	dfs(1,-1,pl,de);
	printf("%I64d\n",pl+de);
	return 0;
}