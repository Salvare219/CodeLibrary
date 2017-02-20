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
#define eps 0.000000001


int n;
double wat[21],num[21][21];
void mult(double a[][21],double b[][21],double c[][21])
{
	double d[21][21]={0};
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				d[i][j]+=a[i][k]*b[k][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=d[i][j];
}
void powmat(double a[][21],int k)
{
	double ii[21][21]={0};
	for(int i=0;i<n;i++)
		ii[i][i]=1;
	while(k)
	{
		if(k%2) mult(a,ii,ii);
		k/=2;
		mult(a,a,a);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=ii[i][j];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,m,temp;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf",wat+i);
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			if(k==0) num[i][i]=1;
			for(int j=0;j<k;j++)
			{
				scanf("%d",&temp);
				num[temp-1][i]=1.0/k;
			}
		}
		scanf("%d",&m);
		powmat(num,m);
		for(int i=0;i<n;i++)
		{
			double sum=0;
			for(int j=0;j<n;j++)
			{
				sum=sum+num[i][j]*wat[j];
			}
			if(i==0) printf("%.2lf",sum);
			else printf(" %.2lf",sum);
		}
		putchar(10);
	}
    return 0;
}