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


int rec[41][41];
char ci[41][41];
int main()
{
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++)
	{
		memset(ci,0,sizeof(ci));
		int n;
		scanf("%d",&n);
		for(int i=0;i<2*n+1;i++)
			for(int j=0;j<2*n+1;j++)
			{
				int dx=i-n,dy=j-n;
				if(dx*dx+dy*dy-n*n<=3 && dx*dx+dy*dy-n*n>=-3) ci[i][j]='*';
				else ci[i][j]=' ';
			}
		printf("Case %d:\n",k+1);
		for(int i=0;i<2*n+1;i++)
		{
			for(int j=0;j<2*n+1;j++)
			{
					putchar(ci[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}