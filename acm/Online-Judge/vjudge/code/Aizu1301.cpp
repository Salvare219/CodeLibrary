#include <bits/stdc++.h>
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
}a,b,c;
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
Point Incenter(Point p1,Point p2,Point p3)
{
    double a=p2/p3,b=p1/p3,c=p1/p2;
    return Point((a*p1.x+b*p2.x+c*p3.x)/(a+b+c),(a*p1.y+b*p2.y+c*p3.y)/(a+b+c));
}
double r1,r2,r3;
Point g1,g2,g3;
inline double line_p(Point p1,Point p2,Point p3)
{
    Point d=p3-p2;
    double dis=p3/p2;
    d=d/dis;
    return fabs(d*(p1-p2));
}
Point p;
const double eps=1e-8;
inline bool ok(Point g)
{
    g1=g;
    r1=line_p(g,a,b);
    Point d2=p-b;
    double l2=p/b;
    d2=d2/l2;
    double l=0,r=l2,mid;
    while(r-l>eps)
    {
        mid=(l+r)*0.5;
        Point t=b+d2*mid;
        if(line_p(t,a,b)>t/g-r1)r=mid;
        else l=mid;
    }
    g2=b+d2*r;
    r2=line_p(g2,a,b);
    Point d3=p-c;
    double l3=p/c;
    d3=d3/l3;
    l=0,r=l3;
    while(r-l>eps)
    {
        mid=(l+r)*0.5;
        Point t=c+d3*mid;
        double l1=line_p(t,b,c),l2=t/g-r1,l3=t/g2-r2;
        if(l1>min(l2,l3))r=mid;
        else l=mid;
    }
    g3=c+d3*r;
    r3=line_p(g3,b,c);
    double dg=g1/g3,dt=g2/g3;
    if(sgn(r1+r3-dg)>=0)
        return 1;
    else
        return 0;
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y))
    {
        if(sgn(a.x)==0&&sgn(a.y)==0&&sgn(b.x)==0&&sgn(b.y)==0&&sgn(c.x)==0&&sgn(c.y)==0)
            break;
        p=Incenter(a,b,c);
        Point d1=p-a;
        double l1=p/a;
        d1=d1/l1;
        double l=0,r=l1,mid;
        while(r-l>eps)
        {
            mid=(l+r)*0.5;
            if(ok(a+d1*mid))r=mid;
            else l=mid;
        }
        ok(a+d1*r);
        //printf("***%lf %lf %lf\n",g1/g2-r1-r2,g2/g3-r3-r2,g1/g3-r1-r3);
        printf("%.7f %.7f %.7f\n",r1,r2,r3);
    }
    return 0;
}
