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


struct p
{
	int c,d;
}ta[200000];
bool cmp(struct p a,struct p b)
{
	return a.d<b.d;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=0;j<t;j++)
	{
		printf("Case %d: ",j+1);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&ta[i].c,&ta[i].d);
		sort(ta,ta+n,cmp);
		long long time=0;
		long long maxxx=0;
		for(int i=0;i<n;i++)
		{
			time=time+ta[i].c;
			maxxx=max((long long)maxxx,time-ta[i].d);
		}
		printf("%I64d\n",maxxx);
	}
	return 0;
}