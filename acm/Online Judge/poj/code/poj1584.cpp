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
}po[3000],c;
double r;
double xmult(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int sgn(double x)
{
    return fabs(x)<1e-6?0:(x>0.0?1:-1);
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n<3) break;
        scanf("%lf%lf%lf",&r,&c.x,&c.y);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        po[n]=po[0];po[n+1]=po[1];
        int dir=0,te;
        bool f=1;
        for(int i=0;i<n;i++)
        {
            te=sgn(xmult(po[i],po[i+1],po[i+2]));
            if(dir==0) dir=te;
            else if(te && te!=dir) f=0;
        }
        if(!f) puts("HOLE IS ILL-FORMED");
        else
        {
            f=1;
            dir=0;
            for(int i=0;i<n;i++)
            {
                te=sgn(xmult(po[i],c,po[i+1]));
                if(dir==0) dir=te;
                else if(te && te!=dir) f=0;
            }
            for(int i=0;i<n;i++)
                if(fabs(xmult(c,po[i],po[i+1]))<r*dis(po[i],po[i+1]))
                    f=0;
            puts(f?"PEG WILL FIT":"PEG WILL NOT FIT");
        }
    }
    return 0;
}
