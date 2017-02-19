#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;



int num[5][5];
int main()
{
//	freopen("1.txt","r",stdin);
	int kong[2][3],vis[2][3]={0},z=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			scanf("%d",&num[i][j]);
			if(num[i][j]==0) 
			{
				vis[0][i]++;
				vis[1][j]++;
				kong[0][z]=i;
				kong[1][z++]=j;
			}
		}
		int sta,sir;
		for(int i=0;i<3;i++)
		{
			if(vis[0][i]==1)
			{
				sta=i;
				sir=0;
				break;
			}
			if(vis[1][i]==1)
			{
				sta=i;
				sir=1;
				break;
			}
		}
	bool ok=0;
	for(int i=1;i<=100000;i++)
	{
		bool flag=1;
		int sum=0,x,y;
		for(int j=0;j<3;j++)
		{
			if(sir==0)
			{
				if(num[sta][j]) sum+=num[sta][j];
				else 
				{
					sum+=i;
					num[sta][j]=i;
					x=sta;y=j;
				}
			}
			else 
			{
				if(num[j][sta]) sum+=num[j][sta];
				else 
				{
					sum+=i;
					num[j][sta]=i;
					x=sta;y=j;
				}
			}
		}
		for(int j=0;j<3;j++)
		{
			int now=0,u=-1,no=-1;
			for(int k=0;k<3;k++)
			{
				if(num[j][k]) now+=num[j][k];
				else 
				{
					u=j;no=k;
				}
			}
			if(u!=-1)
			{
				num[u][no]=sum-now;
				if(sum==now) 
				{
					flag=0;
					break;
				}
				now=sum;
			}
			if(sum!=now)
			{
				flag=0;
				break;
			}
		}
		for(int k=0;k<3;k++)
		{
			int now=0,u=-1,no=-1;
			for(int j=0;j<3;j++)
			{
				if(num[j][k]) now+=num[j][k];
				else 
				{
					u=j;no=k;
				}
			}
			if(u!=-1)
			{
				num[u][no]=sum-now;
				if(sum==now) 
				{
					flag=0;
					break;
				}
				now=sum;
			}
			if(sum!=now)
			{
				flag=0;
				break;
			}
		}
		if(num[0][0]+num[1][1]+num[2][2]!=sum)
		{
			flag=0;
		}
		if(num[2][0]+num[1][1]+num[0][2]!=sum) flag=0;
		if(flag) 
		{
			ok=1;
			break;
		}
		else 
		{
			for(int j=0;j<3;j++)
			{
				num[kong[0][j]][kong[1][j]]=0;
			}
		}
	}
	if(ok) 
	{
		for(int i=0;i<3;i++)
		{
			for(int k=0;k<3;k++)
				printf("%d ",num[i][k]);
			putchar(10);
		}
	}
    return 0;
}
