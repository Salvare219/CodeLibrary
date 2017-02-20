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


int num[10000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==0) 
		{
			scanf("%d",&n);
			printf("0\n");
		}
		else
		{
			for(int i=n;i>-1;i--)
			scanf("%d",num+i);
			for(int i=0;i<n+1;i++)
			{
				num[i]=num[i]*i;
			}
			printf("%d",num[n]);
			for(int i=n-1;i>0;i--)
				printf(" %d",num[i]);
			if(num[0]!=0) printf("%d\n",num[0]);
			else putchar(10);
		}
	}
    return 0;
}