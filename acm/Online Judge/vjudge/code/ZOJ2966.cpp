#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define INF 0x7fffffff


int root[502];
int n,m;
struct p
{
	int x,y,wei;
}dis[505*505];
int find(int p)
{
	return (p==root[p])?p:root[p]=find(root[p]);
}
bool cmp(struct p a,struct p b)
{
	return a.wei<b.wei;
}
int cccc(int c)
{
	int ans=0;
	sort(dis,dis+m,cmp);
	int time=0;
	for(int i=0;i<m;i++)
	{
		int a=find(dis[i].x),b=find(dis[i].y);
		if(a!=b)
		{
			ans+=dis[i].wei;
			root[a]=b;
			time++;
		}
		if(time==c) break;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(dis,0,sizeof(dis));
		int x,y,temp,time=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			root[i]=i;
		int times=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&temp);
			if(temp==0)
			{
				int a=find(x),b=find(y);
				if(a!=b) time++; 
				root[a]=b;
			}
			else
			{
				dis[times].x=x;
				dis[times].y=y;dis[times].wei=temp;
				times++;
			}
		}
		int kk=0;
		printf("%d\n",cccc(n-1-time));
	}
    return 0;
}