#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


long long sum=0,temp;
char str[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		if(strcmp("donate",str)==0) 
		{
			scanf("%lld",&temp);
			sum=sum+temp;
		}
		else 
		{
			printf("%lld\n",sum);
		}
	}
    return 0;
}