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
    bool operator<(Point a)const{return a.x==x?y<a.y:x<a.x;}
}po[8];
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
bool in(int i)
{
    return po[i].x<=po[5].x && po[i].x>=po[2].x && po[i].y<=po[5].y && po[i].y>=po[2].y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<4;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        po[4].x=po[2].x;po[4].y=po[3].y;
        po[5].x=po[3].x;po[5].y=po[2].y;
        sort(po+2,po+6);
        if(in(0) && in(1)) puts("T");
        else
        {
            if(cross(po[0],po[1],po[2],po[4]) || cross(po[0],po[1],po[4],po[5]) ||
               cross(po[0],po[1],po[5],po[3]) || cross(po[0],po[1],po[3],po[2])) puts("T");
            else puts("F");
        }
    }
    return 0;
}
