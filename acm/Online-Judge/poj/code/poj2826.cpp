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
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator/(double a){return Point(x/a,y/a);}
    Point operator*(double a){return Point(x*a,y*a);}
    bool operator==(Point a){return x==a.x&&y==a.y;}
}a[2],b[2],c[2],cro;
struct Line
{
    double a,b,c;
    Line(Point p0=Point(1.0,1.0),Point p1=Point())
    {
        a=p1.y-p0.y;b=p0.x-p1.x;
        c=(p0.y-p1.y)*p0.x+(p1.x-p0.x)*p0.y;
    }
    Point intersect(Line l)
    {
        return Point(1.0*(b*l.c-l.b*c)/(l.b*a-b*l.a),
                     1.0*(l.a*c-a*l.c)/(a*l.b-l.a*b));
    }
}l1,l2,l3;
bool in(Point p1,Point p2,Point p3)
{
    return p1.x<=max(p2.x,p3.x) && p1.x>=min(p2.x,p3.x) &&
           p1.y<=max(p2.y,p3.y) && p1.y>=min(p2.y,p3.y);
}
bool can(Point p1,Point p2,Point p3)
{
    if(p1.x<=max(p2.x,p3.x) && p1.x>=min(p2.x,p3.x)) return 1;
    if((p2.y-p1.y)*(p3.x-p1.x)>(p3.y-p1.y)*(p2.x-p1.x)) return p3.x>p2.x;
    else return p2.x>p3.x;
}
double xmult(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<2;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=0;i<2;i++)
            scanf("%lf%lf",&b[i].x,&b[i].y);
        if(abs(a[0].y-a[1].y)<1e-6 || abs(b[0].y-b[1].y)<1e-6) puts("0.00");
        else
        {
            l1=Line(a[0],a[1]);l2=Line(b[0],b[1]);
            if(abs(l1.a*l2.b-l1.b*l2.a)<1e-6) puts("0.00");
            else
            {
                cro=l1.intersect(l2);
                if(in(cro,a[0],a[1])==0 || in(cro,b[0],b[1])==0) puts("0.00");
                else
                {
                    if(a[1].y>cro.y) swap(a[1],a[0]);
                    if(b[1].y>cro.y) swap(b[1],b[0]);
                    if(can(cro,a[0],b[0])==0) puts("0.00");
                    else
                    {
                        if(a[0].y<b[0].y) b[0]=l2.intersect(Line(Point(0.0,a[0].y),Point(1.0,a[0].y)));
                        else a[0]=l1.intersect(Line(Point(0.0,b[0].y),Point(1.0,b[0].y)));
                        printf("%.2f\n",abs(xmult(cro,a[0],b[0]))/2);
                    }
                }
            }
        }
    }
    return 0;
}
