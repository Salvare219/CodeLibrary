#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    int x,y;
}pa[100],pb[100];
int main()
{
    int n,ti=1;
    while(scanf("%d",&n)&&n)
    {
        int x,y,z,ca=0,cb=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(z==0)
            {
                pa[ca].x=x;
                pa[ca++].y=y;
            }
            else
            {
                pb[cb].x=x;
                pb[cb++].y=y;
            }
        }
        int lim=1<<ca;
        int ans=2000*2000;
        for(int i=0;i<lim;i++)
        {
            int lx=2000,rx=-2000,ly=2000,gy=-2000;
            int cnt=0;
            for(int j=0;j<ca;j++)
                if((1<<j)&i)
                {
                    lx=min(lx,pa[j].x);
                    rx=max(rx,pa[j].x);
                    ly=min(ly,pa[j].y);
                    gy=max(gy,pa[j].y);
                    cnt++;
                }
            if(cnt>=ca/2)
            {
                int f=1;
                for(int j=0;j<cb;j++)
                    if(pb[j].x<=rx&&pb[j].x>=lx)
                    {
                        if(pb[j].y<=gy&&pb[j].y>=ly)
                        {
                            f=0;
                            break;
                        }
                    }
                if(f)ans=min(ans,(rx-lx)*(gy-ly));
            }
        }
        printf("Case %d: ",ti++);
        if(ans==2000*2000)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
