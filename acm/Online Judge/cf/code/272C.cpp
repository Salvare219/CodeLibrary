#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<hash_map>
using namespace std;



long long num[500000];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",num+i);
	}
	int x,y;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		long long ans=max(num[0],num[x-1]);
		printf("%I64d\n",ans);
		num[0]=ans+y;
		num[x-1]=ans+y;
	}
	return 0;
}