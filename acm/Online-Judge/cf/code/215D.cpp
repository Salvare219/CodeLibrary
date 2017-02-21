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


int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,t,T,x,cost,dif;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&t,&T,&x,&cost);
		dif=max(0,T-t);
		if(dif==0) 
			ans+=(long long)x*m+cost;
		else 
			ans+=min((long long)(m+dif-1)/dif*cost,cost+(long long)x*m*(m>dif));
	}
	printf("%I64d\n",ans);
    return 0;
}