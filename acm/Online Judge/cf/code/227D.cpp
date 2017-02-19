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



int num[100005];
long long sum[100005],dp[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,q,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",num+i);
	sort(num,num+n,cmp);
	scanf("%d",&q);
	for(int i=0;i<n;i++)
	{
		if(i) sum[i]=sum[i-1]+num[i];
		else sum[i]=num[0];
	}
	long long ans,deep;
	while(q--)
	{
		ans=0;deep=1;
		scanf("%d",&k);
		if(dp[k]) ans=dp[k];
		else 
		{
			for(long long j=0;j<n;j=j*k+k)
			{
				if(j*k+k<n) ans+=deep*(sum[j*k+k]-sum[j]);
				else ans+=deep*(sum[n-1]-sum[j]);
				deep++;
			}
			dp[k]=ans;
		}
		printf("%I64d ",ans);
	}
	putchar(10);
    return 0;
}