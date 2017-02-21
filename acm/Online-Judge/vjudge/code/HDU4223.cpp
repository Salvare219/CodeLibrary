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


long long sum[2000];
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		printf("Case %d: ",j+1);
		int n,temp;
		scanf("%d",&n);
		sum[0]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(i==0) sum[1]=temp;
			else sum[i+1]=sum[i]+temp;
		}
		int kk=0;
		sort(sum,sum+n+1);
		long long min=INF;
		for(int i=1;i<=n;i++)
			if(sum[i]-sum[i-1]<min) min=sum[i]-sum[i-1];
		printf("%lld\n",min);
	}
    return 0;
}