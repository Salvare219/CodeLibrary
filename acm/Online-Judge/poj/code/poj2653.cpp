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
}po[100000][2];
double xmult(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool cross(Point a,Point b,Point c,Point d)
{
    if(min(a.x,b.x) <= max(c.x,d.x) && min(c.x,d.x) <= max(a.x,b.x) &&
       min(a.y,b.y) <= max(c.y,d.y) && min(c.y,d.y) <= max(a.y,b.y))
       return xmult(a,b,c)*xmult(a,b,d)<=0.0 && xmult(c,d,a)*xmult(c,d,b)<=0.0;
    else return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&po[i][0].x,&po[i][0].y,&po[i][1].x,&po[i][1].y);
        printf("Top sticks: ");bool p=0;
        for(int i=0;i<n;i++)
        {
            bool f=1;
            for(int j=i+1;j<n;j++)
                if(cross(po[i][0],po[i][1],po[j][0],po[j][1]))
                {
                    f=0;
                    break;
                }
            if(f)
            {
                if(p) printf(", ");
                printf("%d",i+1),p=1;
            }
        }
        puts(".");
    }
    return 0;
}
