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
}s[2],t[2],lef[5000],rig[5000],po[5000][2];
struct Line
{
    double a,b,c;
    Line(Point p0=Point(1,1),Point p1=Point())
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
double xmult(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dis(Point p0,Point p1)
{
    return sqrt((p0.x-p1.x)*(p0.x-p1.x)+(p0.y-p1.y)*(p0.y-p1.y));
}
double temp;
bool cmp(Point p0,Point p1)
{
    temp=xmult(t[0],p0,p1);
    if(temp>0.0 || (abs(temp)<1e-8 && dis(t[0],p0)>dis(t[0],p1))) return 1;
    else return 0;
}
bool cmp2(Point p0,Point p1)
{
    temp=xmult(t[1],p0,p1);
    if(temp>0 || (abs(temp)<1e-8 && dis(t[1],p0)>dis(t[1],p1))) return 1;
    else return 0;
}
bool cross(Point p0,Point p1,Point p2,Point p3)
{
    if(min(p0.x,p1.x) <= max(p2.x,p3.x) && min(p2.x,p3.x) <= max(p0.x,p1.x) &&
       min(p0.y,p1.y) <= max(p2.y,p3.y) && min(p2.y,p3.y) <= max(p0.y,p1.y))
       return xmult(p0,p1,p2)*xmult(p0,p1,p3)<0.0 && xmult(p2,p3,p0)*xmult(p2,p3,p1)<0.0;
    else return 0;
}
int main()
{
    double x,y,z;
    while(scanf("%lf%lf%lf",&x,&y,&z))
    {
        if(x==0.0 && y==0.0 && z==0.0) break;
        t[0]=Point(x,z);t[1]=Point(y,z);
        scanf("%lf%lf%lf",&x,&y,&z);
        s[0]=Point(x,z);s[1]=Point(y,z);
        int n,w=0;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf",&x,&y,&z);
            if(z>=t[0].y)
            {
                w++;
                continue;
            }
            po[i][0]=rig[i]=Point(x,z);
            po[i][1]=lef[i]=Point(y,z);
        }
        n-=w;
        lef[n]=s[0];rig[n]=s[1];
        sort(lef,lef+n+1,cmp);
        sort(rig,rig+n+1,cmp2);
        l3=Line(s[0],s[1]);
        double ans=0.0;
        for(int i=0;i<=n;i++)
        {
            l1=Line(t[0],lef[i]);l2=Line(t[1],rig[i]);
            Point a=l1.intersect(l3),b=l2.intersect(l3);
            bool f=0;
            for(int i=0;i<n;i++)
                if(cross(po[i][0],po[i][1],t[0],a) || cross(po[i][0],po[i][1],t[1],b)) f=1;
            if(f) continue;
            ans=max(ans,b.x-a.x);
        }
        if(ans<1e-8) puts("No View");
        else printf("%.2f\n",ans);
    }
    return 0;
}
