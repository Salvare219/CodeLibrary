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


int main()
{
	int mag[4][4],num[4][4]={0};
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			scanf("%d",&mag[i][j]);
			if(i<2 && j<2) num[0][mag[i][j]-1]++;
			else if(i<2 && j>=2) num[1][mag[i][j]-1]++;
			else if(i>=2 && j<2) num[2][mag[i][j]-1]++;
			else num[3][mag[i][j]-1]++;
		}
		int max=0,flag=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(num[i][j]>max) 
			{
				max=num[i][j];
				flag=i*10+j+1;
			}
	int step=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(mag[i][j]==flag%10)
			{
				int tt;
				if(i<2 && j<2) tt=0;
				else if(i<2 && j>=2) tt=1;
				else if(i>=2 && j<2) tt=2;
				else tt=3;
				if(tt==flag/10) continue;
				else
				{
					if(tt+flag/10==3) step+=2;
					else step++;
				}
			}
			printf("%d\n",step);
    return 0;
}