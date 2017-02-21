#include<bits/stdc++.h>
using namespace std;

double dp[25];
int C[25][25];

int main()
{
	int n,i,j;
	double p,t;
	for(i=0;i<=20;i++)
		for(C[i][0]=C[i][i]=j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	scanf("%d%lf",&n,&p);
	for(dp[1]=1,i=2;i<=n;dp[i++]=1-t)
		for(t=0,j=1;j<i;j++)
			t+=dp[j]*pow(1-p,j*(i-j))*C[i-1][j-1];
	printf("%.12f\n",dp[n]);
	return 0;
}
