#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
 //   freopen("1.txt","r",stdin);
    int a,x,y;
    scanf("%d%d%d",&a,&x,&y);
    int t=y/a,r=y%a;
    if(r==0) puts("-1");
    else
    {
        if(t<1)
        {
            if(abs(x*2)>=a) puts("-1");
            else puts("1");
        }
        else
        {
            t--;
            r=t/2;t%=2;
            if(t)
            {
                if(abs(x)>=a || x==0) puts("-1");
                else
                {
                    if(x>0) printf("%d\n",3*r+4);
                    else printf("%d\n",3*r+3);
                }
            }
            else
            {
                if(abs(x*2)>=a) puts("-1");
                else printf("%d\n",3*r+2);
            }
        }
    }
    return 0;
}


