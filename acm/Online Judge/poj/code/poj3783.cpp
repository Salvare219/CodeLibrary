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


int dp[55][1005];
int ans[55][1005];
void sol()
{
	dp[1][1]=1;
	for(int i=1;i<51;i++)
		for(int j=1;j<1001;j++)
			dp[i][j]=min(1000,dp[i-1][j-1]+dp[i][j-1]+1);
	for(int i=1;i<51;i++)
		for(int j=1;j<1001;j++)
		{
			if(ans[i][dp[i][j]]==0) ans[i][dp[i][j]]=j;
		}
}
int main()
{
	sol();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c,fin;
		scanf("%d%d%d",&a,&b,&c);
		fin=ans[b][c];
		while(fin==0) fin=ans[b][++c];
		printf("%d %d\n",a,fin);
	}
	return 0;
}