#include<bits/stdc++.h>
using namespace std;

int x[40005],y[40005];

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	int xx,yy,n,i;
	for(scanf("%d%d%d",&xx,&yy,&n),i=0;i<n;i++)
		scanf("%d%d",x+i,y+i);
	x[n]=0;y[n]=0;n++;
	x[n]=xx+1;y[n]=yy+1;n++;
	sort(x,x+n);sort(y,y+n);
	for(i=1,xx=yy=0;i<n;i++)
		xx=max(xx,x[i]-x[i-1]-1),yy=max(yy,y[i]-y[i-1]-1);
	printf("%d\n",xx*yy);
	return 0;
}
