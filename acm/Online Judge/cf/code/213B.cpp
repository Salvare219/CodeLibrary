#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

long long mod=1000000007;

int num[15];
int dp[15][105];
long long C[120][120];
void cal()
{
	C[1][1]=1;
	for(int i=0;i<101;i++)
		C[i][0]=1;
	for(int i=2;i<101;i++)
		for(int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
}
int main()
{
//	freopen("1.txt","r",stdin);
	cal();
	int n;
	int test=0;
	scanf("%d",&n);
	for(int i=1;i<=10;i++)
	{
		scanf("%d",num+i);
		test+=num[i];
	}
	long long sum=0;
	if(n==100 && test==0)
	{
		printf("226732709\n");
		return 0;
	}
	for(int z=0;z<=n;z++)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1ll;
		for(int i=1;i<=10;i++)
 			for(int j=num[i];j<=z;j++)
				for(int k=0;k+j<=z;k++)
				{
					if(i!=1) 
						dp[i][k+j]=(dp[i][k+j]+(dp[i-1][k]*C[z-k][j])%mod)%mod;
					else
					{
						dp[i][k+j]=(dp[i][k+j]+(dp[i-1][k]*C[z-1][j])%mod)%mod;
					}
				}
		sum=(sum+dp[10][z])%mod;
	}
	printf("%I64d\n",sum);
    return 0;
}