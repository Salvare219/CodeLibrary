#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


int x1,ys,x2,y2,b,c,d;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Case %d:\n",i+1);
		scanf("%d%d%d%d%d%d%d",&x1,&ys,&x2,&y2,&b,&c,&d);
		int dx=x2-x1,dy=y2-ys;
		double s=dx*dx+dy*dy;
		double dp=(d*d-b*b+s+c*c-2*sqrt(s)*c)/(2*(sqrt(s)-c));
		double dpp=d*d-dp*dp;
	/*	double x5=(dp/sqrt(s))*(x2-x1)+x1,y5=(dp/sqrt(s))*(y2-y1)+y1;
		double x6=x2-(1-(c-dp)/s)*(x2-x1),y5=y2-(1-(c-dp)/s)*(y2-y1);
		double x4=*/
		double x4=x1+(dp/sqrt(s))*dx-dy*sqrt(dpp/s);
		double y4=ys+(dp/sqrt(s))*dy+sqrt(dpp/s)*dx;
		double x3=(c/sqrt(s))*dx+x4,y3=(c/sqrt(s))*dy+y4;
		printf("%lf %lf %lf %lf\n",x3,y3,x4,y4);
	}
    return 0;
}