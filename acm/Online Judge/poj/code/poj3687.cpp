#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


int n,m,ans[205],sum[205],mat[205][205]={0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(mat,0,sizeof(mat));
		memset(sum,0,sizeof(sum));
		int temp1,temp2,flag=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&temp1,&temp2);
			if(mat[temp2-1][temp1-1]) continue;
			mat[temp2-1][temp1-1]=1;
			sum[temp1-1]++;
		}
		if(flag) printf("-1\n");
		else 
		{
			int temp[205],i,j;
			for(int i=n-1;i>-1;i--)
			{
				flag=1;
				for(int j=n-1;j>-1;j--)
				{
					if(sum[j]==0)
					{
						sum[j]=1000;
						for(int k=0;k<n;k++)
						{
							if(mat[j][k]==1) sum[k]--;
						}
						temp[i]=j;
						flag=0;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) printf("-1\n");
			else
			{
				for(int i=0;i<n;i++)
					ans[temp[i]]=i+1;
				for(int i=0;i<n;i++)
					if(i != n-1) printf("%d ",ans[i]);
					else printf("%d\n",ans[i]);
			}
		}
	}
	return 0;
}