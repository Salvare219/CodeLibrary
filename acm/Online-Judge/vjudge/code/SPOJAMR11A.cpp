#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


int n,m;
int mag[505][505];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
memset(mag,0,sizeof(mag));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&mag[i][j]);
		for(int i=n-1;i>-1;i--)
			mag[i][m-1]=(mag[i+1][m-1]-mag[i][m-1]<0)?0:mag[i+1][m-1]-mag[i][m-1];
		for(int i=m-2;i>-1;i--)
			mag[n-1][i]=(mag[n-1][i+1]-mag[n-1][i]<0)?0:mag[n-1][i+1]-mag[n-1][i];
		for(int i=n-2;i>-1;i--)
			for(int j=m-2;j>-1;j--)
			{
				mag[i][j]=min(mag[i+1][j],mag[i][j+1])-mag[i][j];
				if(mag[i][j]<0) mag[i][j]=0;
			}
		printf("%d\n",mag[0][0]+1);
	}
    return 0;
}