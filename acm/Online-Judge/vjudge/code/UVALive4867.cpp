#include<cstdio>   
#include<cstring>   
#include<math.h>   
#include<stdlib.h>   
#include<algorithm>   
using namespace std;   


int mat[1002][1002],sum[1002][1002],con[1002][1002],a,b;
int main()   
{   
	while(scanf("%d%d",&a,&b))
	{
		if(a==0 && b==0) break;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				scanf("%d",&mat[i][j]);
		for(int i=0;i<a;i++)
		{
			int flag=b-1;
			for(int j=b-1;j>-1;j--)
			{
				if(mat[i][j]==0) 
				{
					flag=j-1;
					con[i][j]=0;
				}
				else con[i][j]=flag-j+1;
			}
		}
		for(int i=0;i<b;i++)
		{
			int flag=a-1;
			for(int j=a-1;j>-1;j--)
			{
				if(mat[j][i]==0) 
				{
					flag=j-1;
					con[j][i]=0;
				}
				else con[j][i]=min(con[j][i],flag-j+1);
			}
		}
		for(int i=0;i<a+1;i++)
			sum[i][b]=0;
		for(int i=0;i<b+1;i++)
			sum[a][i]=0;
		for(int i=a-1;i>-1;i--)
			for(int j=b-1;j>-1;j--)
				sum[i][j]=mat[i][j]+sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1];
		int max=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
			{
				int dis=con[i][j];
				int tot=dis*dis,x,y;
				while(tot>=sum[i][j]-sum[i][j+dis]-sum[i+dis][j]+sum[i+dis][j+dis])
				{
					if(dis==0) break;
					if(tot==sum[i][j]-sum[i][j+dis]-sum[i+dis][j]+sum[i+dis][j+dis])
						if(dis>max) 
						{
							max=dis;
							break;
						}
					dis--;
					tot=dis*dis;
				}
			}
			printf("%d\n",max);
	}
    return 0;
}    