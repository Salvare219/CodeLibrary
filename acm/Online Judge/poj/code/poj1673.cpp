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
}po[3];
Point Orthocenter(Point p0,Point p1,Point p2)
{
    double a1,b1,a2,b2,c1,c2;
    a1 = p2.x-p1.x; b1=p2.y-p1.y;c1 = 0;
    a2 = p2.x-p0.x; b2=p2.y-p0.y;c2 = (p1.x-p0.x)*a2+(p1.y-p0.y)*b2;
    double d = a1 * b2 - a2 * b1;
    return Point(p0.x+(c1*b2-c2*b1)/d,p0.y+(a1*c2-a2*c1)/d);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<3;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        po[0]=Orthocenter(po[0],po[1],po[2]);
        printf("%.4f %.4f\n",po[0].x,po[0].y);
    }
    return 0;
}
