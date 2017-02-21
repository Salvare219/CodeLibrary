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
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
}po[1600],hull[1600];
struct Line
{
    Point s,t;
    double arg;
    Line(){}
    Line(Point a,Point b){s=a;t=b;arg=atan2(b.y-a.y,b.x-a.x);}
    Point operator&(const Line&a)const{return (t-s)*((s-a.s)*(a.s-a.t))/((s-t)*(a.s-a.t))+s;}
    bool operator<(const Line&a)const
    {
        if(fabs(arg-a.arg)>1e-6)return arg<a.arg;
        else return (a.s-s)*(t-s)>1e-9;
    }
}q[1600],l[1600],te[1600];
const double pi=acos(-1.0);
int halfplaneintersection(Line v[],int n,Point ans[])
{
    int front=0,tail=0;q[0]=v[0];
    //sort(v,v+n);
    for(int i=1;i<n;i++)
        if(fabs(v[i-1].arg-v[i].arg)>1e-6)
        {
            while(front<tail&&(ans[tail-1]-v[i].s)*(v[i].t-v[i].s)>1e-9)tail--;
            while(front<tail&&(ans[front]-v[i].s)*(v[i].t-v[i].s)>1e-9)front++;
            if(fabs(q[tail].arg+pi-v[i].arg)<1e-6)return 0;
            ans[tail]=v[i]&q[tail];q[++tail]=v[i];
        }
    while(front<tail&&(ans[tail-1]-q[front].s)*(q[front].t-q[front].s)>1e-9)tail--;
    ans[tail]=q[tail]&q[front];
    for(int i=front;i<=tail;i++)ans[i-front]=ans[i];
    return tail-front+1;
}
int n;
inline bool ok(double mid)
{
    Point dir;
    for(int i=0;i<n;i++)
    {
        dir=l[i].t-l[i].s;
        dir=Point(-dir.y,dir.x);
        dir=dir*mid/(dir/Point(0,0));
        te[i]=Line(l[i].s+dir,l[i].t+dir);
    }
    return halfplaneintersection(te,n,hull)>2;
}
int main()
{
    int n;
    double r;
    scanf("%d%lf",&n,&r);r-=1e-8;
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&po[i].x,&po[i].y);
    po[n]=po[0];
    Point dir;
    for(int i=n;i>0;i--)
    {
        dir=po[i-1]-po[i];
        dir=dir*r/(dir/Point(0,0));
        swap(dir.x,dir.y);dir.x=-dir.x;
        l[i-1]=Line(po[i]+dir,po[i-1]+dir);
    }
    int k=halfplaneintersection(l,n,hull),fa=1;
    double ans=0.0,cost;
    Point p1,p2;hull[k]=hull[0];
    for(int i=0;i<k;i++)
    {
        while(fabs((hull[i+1]-hull[i])*(hull[fa+1]-hull[i]))>fabs((hull[i+1]-hull[i])*(hull[fa]-hull[i])))
            fa==k-1?fa=0:fa++;
        if(hull[i+1]/hull[fa]>ans) p1=hull[i+1],p2=hull[fa],ans=hull[i+1]/hull[fa];
        if(hull[i]/hull[fa]>ans) p1=hull[i],p2=hull[fa],ans=hull[i]/hull[fa];
    }
    printf("%.6f %.6f\n%.6f %.6f\n",p1.x,p1.y,p2.x,p2.y);
    return 0;
}
