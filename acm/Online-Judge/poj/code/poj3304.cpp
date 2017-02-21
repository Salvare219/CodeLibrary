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
}po[105][2];
int n;
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
double dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool ok(int x,int y)
{
    Point a,b;
    for(int i=0;i<4;i++)
    {
        a=po[x][i>>1],b=po[y][i&1];
        if(dis(a,b)<1e-8) continue;
        b=a-b;
        a=a+b*1e10;b=a-b*2e10;
        bool f=1;
        for(int j=0;j<n && f;j++)
            if(x!=j && y!=j && cross(a,b,po[j][0],po[j][1])==0) f=0;
        if(f) return 1;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&po[i][0].x,&po[i][0].y,&po[i][1].x,&po[i][1].y);
        bool f=0;
        if(n==1) f=1;
        else
        {
            for(int i=0;i<n && !f;i++)
                for(int j=i+1;j<n && !f;j++)
                    if(ok(i,j)) f=1;
        }
        puts(f?"Yes!":"No!");
    }
    return 0;
}
