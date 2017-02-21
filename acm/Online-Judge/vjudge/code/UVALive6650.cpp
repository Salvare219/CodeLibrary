#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int l,w,h,v;
        int x,y;
        int x1=0,y1=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&l,&w,&h);
            x=2*h-1;y=2*h;
            if(x*y1>x1*y)
            {
                x1=x;y1=y;
                v=l*w*h;
            }
            else if(x*y1==x1*y)
            {
                v=max(v,l*w*h);
            }
        }
        printf("%d\n",v);
    }
	return 0;
}
