#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int tt[200],b[200];
bool vis[200];
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0) break;
		int sum=0,max=0,temax;
		int car=0;
		memset(tt,0,sizeof(tt));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++) scanf("%d%d",tt+i,b+i);
		for(int i=n-1;i>-1;i--)
		{
			while(b[i])
			{
				b[i]--;
				int max=0,flag=-1;
				for(int j=i+1;j<n;j++)
				{
					if(tt[j]>max && vis[j]==0)
					{
						max=tt[j];
						flag=j;
					}
				}
				if(flag==-1) break;
				tt[flag]/=2;
				vis[flag]=1;
			}
		}
		for(int i=0;i<n;i++)
			sum+=tt[i];
		printf("%d\n",sum);
	}
    return 0;
}
