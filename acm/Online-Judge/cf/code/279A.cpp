#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;




int main()
{
//	freopen("1.txt","r",stdin);
	int x,y,ans;
	scanf("%d%d",&x,&y);
	if(x>=0 && y>=0)
	{
		if(x>=y) ans=4*x-3;
		else ans=4*y-2;
	}
	else if(x>=0 &&y<0)
	{
		if(x-1>-y) ans=4*x-3;
		else ans=-4*y;
	}
	else if(x<0 && y>=0)
	{
		if(-x>y) ans=-4*x-1;
		else ans=4*y-2;
	}
	else
	{
		if(x>y) ans=-4*y;
		else ans=-4*x-1;
	}
	if(x==0 && y==0) ans=0;
	if(x==1 && y==0) ans=0;
	printf("%d\n",ans);
    return 0;
}