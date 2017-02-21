#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct p
{
    double l,r;
    bool operator<(p a)const{return l<a.l;}
}q[600];
const double eps = 1e-6;
const double pi=acos(-1.0);
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        double x,y,r,cx,cy;
        double th,dth,dis;
        scanf("%lf%lf",&cx,&cy);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&x,&y,&r);
            if(sgn(r)==0) continue;
        //    th=atan2(cy-y,cx-x);dis=(cx-x)*(cx-x)+(cy-y)*(cy-y);
        //    dth=atan2(r,sqrt(dis-r*r));
            dis=sqrt((cx-x)*(cx-x)+(cy-y)*(cy-y));
            th=asin((cx-x)/dis);dth=asin(r/dis);
            q[i].l=cx-cy*tan(th+dth);
            q[i].r=cx-cy*tan(th-dth);
        }
        sort(q,q+n);
        double lat=q[0].r;
        int i=0;
        while(i<n)
        {
            printf("%.2f ",q[i].l);
            while(i<n && sgn(lat-q[i].l)!=-1) lat=max(lat,q[i++].r);
            printf("%.2f\n",lat);lat=q[i].r;
        }
        putchar(10);
    }
    return 0;
}
