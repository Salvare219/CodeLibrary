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
#define INF 0x7fffffff


long long dp[160][160][160];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k,s;
		scanf("%d%d%d%d",&n,&m,&k,&s);
		memset(dp,0,sizeof(dp));
		dp[0][s-1][0]=1;
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			for(int j=0;j<n;j++)
			{
				for(int r=0;r<=k;r++)
				{
					if(x==j) dp[i+1][y][r+1]+=dp[i][j][r];
					else if(y==j) dp[i+1][x][r+1]+=dp[i][j][r];
					else dp[i+1][j][r+1]+=dp[i][j][r];
					dp[i+1][j][r]+=dp[i][j][r];
				}
			}
		}
		long long maxs=0;
		int ans=s-1;
		for(int i=0;i<n;i++)
		{
			if(dp[m][i][k]>maxs) 
			{
				maxs=dp[m][i][k];
				ans=i;
			}
		}
		printf("%d\n",ans+1);
 	}
    return 0;
}