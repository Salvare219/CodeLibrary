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


int x[101],y[101],z[101],l[101];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,xmin=400,ymin=400,xmax=-1,ymax=-1;
		scanf("%d",&n);
		int x1,y1,z1,w1;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,z+i,l+i);
			x[i]=x1+100;y[i]=y1+100;
			if(xmin>x[i]) xmin=x[i];
			if(ymin>y[i]) ymin=y[i];
			if(xmax<x[i]) xmax=x[i];
			if(ymax<y[i]) ymax=y[i];
		}
		double titi=0;
		int dx,dy,dis;
		for(int i=xmin;i<=xmax;i++)
			for(int j=ymin;j<=ymax;j++)
			{
				double tp=0;
				for(int k=0;k<n;k++)
				{
					dx=x[k]-i;dy=y[k]-j;
					dis=dx*dx+dy*dy+z[k]*z[k];
					tp=tp+(double)l[k]*z[k]/(dis*sqrt((double)dis));
				}
				if(tp>titi) titi=tp;
			}
		printf("%.2lf\n",titi);
	}
    return 0;
}