#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    double x,y,v;
    Point(double a=0.0,double b=0.0,double c=0.0){x=a;y=b;v=c;}
    double operator/(const Point&a)const
    {return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));}
}po[60];
int n;
const double pi=acos(-1.0);
const double eps=1e-7;
int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
pair<double,bool>arg[120];
bool ok(double mid)
{
    double th,dth,p1,p2,r1,r2,d;
    for(int j=0;j<n;j++)
    {
        int k=0,cnt=0,tot=0;
        bool f=1;
        for(int i=0;i<n;i++)
            if(i!=j)
            {
                d=po[i]/po[j];r1=po[j].v*mid;r2=po[i].v*mid;
                if(sgn(d+r1-r2)<=0)cnt++;
                else if(sgn(d+r2-r1)<=0){f=0;break;}
                else if(sgn(d-r2-r1)<0)
                {
                    th=atan2(po[i].y-po[j].y,po[i].x-po[j].x);
                    dth=acos((r1*r1+d*d-r2*r2)/(2*d*r1));
                    p1=th-dth;p2=th+dth;
                    if(sgn(p1+pi)==-1)p1+=2*pi,cnt++;
                    if(sgn(p2-pi)==1)p2-=2*pi,cnt++;
                    arg[k++]=make_pair(p1,0);arg[k++]=make_pair(p2,1);
                }
                else{f=0;break;}
            }
        if(!f)continue;
        sort(arg,arg+k);tot=cnt;
        for(int i=0;i<k;i++)
            if(arg[i].second)cnt--;
            else tot=max(tot,++cnt);
        if(tot==n-1)return 1;
    }
    return 0;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&po[i].x,&po[i].y,&po[i].v);
        double l=0,r=4e6,mid;
        while(r-l>1e-6)
        {
            mid=(l+r)/2;
            if(ok(mid))r=mid;
            else l=mid;
        }
        printf("%.6f\n",r);
    }
    return 0;
}
