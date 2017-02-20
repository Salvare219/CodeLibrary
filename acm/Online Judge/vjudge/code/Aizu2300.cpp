#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  
#define eps 0.000001

int n,m;
double dis[21][21],max1=0;
double x[21],y[21],z[21];
bool vis[21]={0};
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lf%lf%lf",x+i,y+i,z+i);
	if(m==1 || m==0) printf("%.20lf\n",0);
	else
	{
		double max=0;
		int mx,my;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				double d1=x[i]-x[j],d2=y[i]-y[j],d3=z[i]-z[j];
				dis[i][j]=dis[j][i]=d1*d1+d2*d2+d3*d3;
			}
		char str[21];
		for(int i=0;i<n;i++) str[i]='1';
		for(int i=0;i<m;i++) str[i]='0';
		str[n]=0;
		do
		{
			double pp=0;
			for(int i=0;i<n;i++)
			{
				if(str[i]=='1') continue;
				for(int j=0;j<n;j++)
				{
					if(str[j]=='1') continue;
					pp=pp+dis[i][j];
				}
			}
			if(pp>max1) max1=pp;
		}while(next_permutation(str,str+n));
		printf("%.20lf\n",max1/2);
	}
    return 0;
}