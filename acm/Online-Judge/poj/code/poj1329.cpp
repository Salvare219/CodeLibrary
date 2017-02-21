#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct Point
{
    double x,y;
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator/(double a){return Point(x/a,y/a);}
    Point operator*(double a){return Point(x*a,y*a);}
    bool operator==(Point a){return x==a.x&&y==a.y;}
    bool operator<(Point a){return x==a.x?y<a.y:x<a.x;}
}p[3];
const double eps=1e-8;
Point circumcenter(Point a,Point b,Point c)
{
    double a1=b.x-a.x,b1=b.y-a.y,c1 =(a1*a1+b1*b1)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2 =(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
}
double dis(Point p1)
{return sqrt(p1.x*p1.x+p1.y*p1.y);}
int main()
{
  while(~scanf("%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y))
    {
        Point c=circumcenter(p[0],p[1],p[2]);
        double r=dis(p[0]-c),a,b,d;
        if(c.x>-eps) printf("(x - %.3f)^2 + ",c.x);
        else printf("(x + %.3f)^2 + ",-c.x);
        if(c.y>-eps) printf("(y - %.3f)^2 = %.3f^2\n",c.y,r);
        else printf("(y + %.3f)^2 = %.3f^2\n",-c.y,r);
        a=2*c.x;b=2*c.y;d=c.x*c.x+c.y*c.y-r*r;
        printf("x^2 + y^2");
        if(a>-eps) printf(" - %.3fx",a);
        else printf(" + %.3fx",-a);
        if(b>-eps) printf(" - %.3fy",b);
        else printf(" + %.3fy",-b);
        if(d>-eps) printf(" + %.3f = 0\n",d);
        else printf(" - %.3f = 0\n",-d);
        putchar(10);
    }
    return 0;
}
