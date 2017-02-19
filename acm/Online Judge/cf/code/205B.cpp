#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


long long num[100005];
int main()
{
	int n,temp;
	long long sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%I64d",num+i);
	for(int i=1;i<n;i++)
	{
		temp=(num[i-1]-num[i]<0)?0:num[i-1]-num[i];
		sum+=temp;
	}
	printf("%I64d\n",sum);
    return 0;
}