#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


bool vis[100000005];
int main()
{
	int n,m,k;
	int poly[120];
	while(scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0) break;
		memset(vis,0,sizeof(bool)*(n+5));
		scanf("%d",&k);
		for(int i=0;i<=k;i++)
		{
			scanf("%d",poly+i);
			poly[i]=poly[i]%(n+1);
		}
		long long sum,x;
		int time=0;
		for(long long i=0;i<=m;i++)
		{
			sum=0;
			x=1;
			for(long long j=0;j<=k;j++)
			{
				sum=(sum+(x*poly[j])%(n+1))%(n+1);
				x=(x%(n+1))*(i%(n+1))%(n+1);
			}
			if(vis[sum%(n+1)]==0)
			{
				vis[sum%(n+1)]=1;
				time++;
			}
		}
		printf("%d\n",time);
	}
    return 0;
}
