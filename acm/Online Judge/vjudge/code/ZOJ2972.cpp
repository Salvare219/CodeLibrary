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


int tt[200][3];
int f[200][2];
int dp[200][200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		memset(dp,0x7f,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d%d%d%d%d",&tt[i][0],&tt[i][1],&tt[i][2],&f[i][0],&f[i][1]);
		for(int i=0;i<=m;i++)
			if(i>=f[n-1][0]) dp[n-1][i]=tt[n-1][0];
			else dp[n-1][i]=tt[n-1][1];
		for(int i=n-2;i>-1;i--)
			for(int j=0;j<=m;j++)
			{
				if(j>=f[i][0]) 
				{
					dp[i][j]=min(dp[i][j],dp[i+1][j-f[i][0]]+tt[i][0]);
				}
				dp[i][j]=min(dp[i][j],dp[i+1][j]+tt[i][1]);
				dp[i][j]=min(dp[i][j],dp[i+1][min(m,j+f[i][1])]+tt[i][2]);
			}
		printf("%d\n",dp[0][m]);
	}
    return 0;
}