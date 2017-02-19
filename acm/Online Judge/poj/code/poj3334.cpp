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
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
}a[1005],b[1005];
int n,m;
const double eps=1e-9;
int sgn(double x)
{
    return fabs(x)<eps?0:(x>0?1:-1);
}
Point cross(Point p1,Point p2,double mid)
{
    return (p2-p1)*(mid-p1.y)/(p2.y-p1.y)+p1;
}
double cal(double mid)
{
    double s=0.0;
    bool f=0;
    Point st;
    for(int i=0;i<n;i++)
        if(sgn(a[i].y-mid)>=0)
        {
            if(f)f=0,s+=(a[i-1]-st)*(cross(a[i-1],a[i],mid)-st);
        }
        else
        {
            if(!f)f=1,st=cross(a[i-1],a[i],mid);
            else s+=(a[i-1]-st)*(a[i]-st);
        }
    f=0;
    for(int i=0;i<m;i++)
        if(sgn(b[i].y-mid)>=0)
        {
            if(f)f=0,s+=(b[i-1]-st)*(cross(b[i-1],b[i],mid)-st);
        }
        else
        {
            if(!f)f=1,st=cross(b[i-1],b[i],mid);
            else s+=(b[i-1]-st)*(b[i]-st);
        }
    return s*0.5;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        double v,d1=1e10,d2=1e10;
        scanf("%lf",&v);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y),d1=min(d1,a[i].y);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            scanf("%lf%lf",&b[i].x,&b[i].y),d2=min(d2,b[i].y);
        double l=min(d1,d2),r=min(min(b[0].y,b[m-1].y),min(a[0].y,a[n-1].y)),mid;
        while(r-l>1e-5)
        {
            mid=(l+r)/2.0;
            if(cal(mid)>v)r=mid;
            else l=mid;
        }
        printf("%.3f\n",l);
    }
    return 0;
}
