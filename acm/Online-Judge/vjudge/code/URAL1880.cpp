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


map<int,int> abp;
int num[3][5000];
int main()
{
	int n[3];
	for(int i=0;i<3;i++)
	{
		int temp;
		scanf("%d",n+i);
		for(int j=0;j<n[i];j++)
		{
			scanf("%d",&num[i][j]);
			abp[num[i][j]]++;
		}
	}
	int time=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<n[i];j++)
		{
			if(abp[num[i][j]]==3)
			{
				time++;
			}
		}
	printf("%d\n",time/3);
    return 0;
}