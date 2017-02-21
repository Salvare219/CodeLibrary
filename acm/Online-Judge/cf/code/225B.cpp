#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;



long long fib[100005];
int ans[100005];
int main()
{
	int s,k;
	scanf("%d%d",&s,&k);
	fib[1]=1;
	int i;
	for(i=2;fib[i-1]<s+5;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(i-j-1<0) break;
			fib[i]+=fib[i-j-1];
		}
	}
	int z=0;
	for(int j=i-1;j>-1;j--)
		if(s>=fib[j]) 
		{
			ans[z++]=fib[j];
			s-=fib[j];
			if(s==0) break;
		}
	printf("%d\n",++z);
	for(int j=0;j<z;j++)
		printf("%d ",ans[j]);
	return 0;
} 				    