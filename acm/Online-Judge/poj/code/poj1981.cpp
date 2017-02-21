#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    double x,y;
    double operator/(const Point&a){return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));}
}po[305];
const double eps=1e-9;
int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
const double pi=acos(-1.0);
pair<double,bool>arg[605];
int cir_point(Point po[],int n,double r)
{
    double d,th,dth,p1,p2;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0,k=0,tot=0;
        for(int j=0;j<n;j++)
            if(i!=j&&sgn((d=po[i]/po[j])-r-r)==-1)
            {
                dth=acos(d*0.5/r);
                th=atan2(po[j].y-po[i].y,po[j].x-po[i].x);
                p1=th-dth;p2=th+dth;
                if(sgn(p1+pi)==-1)p1+=2*pi,cnt++;
                if(sgn(p2-pi)==1)p2-=2*pi,cnt++;
                arg[k++]=make_pair(p1,1);arg[k++]=make_pair(p2,0);
            }
        sort(arg,arg+k);
        for(int j=0;j<k;j++)
            if(!arg[j].second)cnt--;
            else tot=max(tot,++cnt);
        ans=max(tot+1,ans);
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        printf("%d\n",cir_point(po,n,1.0));
    }
    return 0;
}
