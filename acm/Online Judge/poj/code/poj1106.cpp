#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct Point
{
    double x,y,arc;
    Point(double a=0.0,double b=0.0,double c=0.0){x=a;y=b;arc=c;}
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator/(double a){return Point(x/a,y/a);}
    Point operator*(double a){return Point(x*a,y*a);}
    bool operator==(Point a){return x==a.x&&y==a.y;}
    bool operator<(Point a)const{return arc<a.arc;}
    double amplit(){return sqrt(x*x+y*y);}
}po[10000],c;
const double eps = 1e-8;
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
int main()
{
    double r;
    const double pi=acos(-1.0);
    while(~scanf("%lf%lf%lf",&c.x,&c.y,&r) && r>=0.0)
    {
        int n;
        double x,y;
        scanf("%d",&n);
        int k=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&po[n].x,&po[n].y);
            if(sgn((po[n]-c).amplit()-r)==1) continue;
            po[n].arc=atan2(po[n].y-c.y,po[n].x-c.x);
            po[k++]=po[n];
        }
        sort(po,po+k);
        for(int i=0;i<k;i++)
            po[i+k]=po[i],po[i+k].arc+=2*pi;
        k<<=1;
        int f=0,ans=0;
        for(int i=0;i<k;i++)
        {
            while(f<k && sgn(po[f].arc-po[i].arc-pi)!=1)
                f++;
            ans=max(ans,f-i);
        }
        printf("%d\n",ans);
    }
    return 0;
}