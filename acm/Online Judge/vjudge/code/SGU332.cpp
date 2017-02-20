#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const double pi=acos(-1.0);
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
}po[10050],hull[10050];
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
}q[10050],l[10050];
int halfplaneintersection(Line v[],int n,Point ans[])
{
    int front=0,tail=0;
    //sort(v,v+n);
    q[0]=v[0];
    for(int i=1;i<n;i++)
        if(fabs(v[i-1].arg-v[i].arg)>1e-6)
        {
            while(front<tail&&(ans[tail-1]-v[i].s)*(v[i].t-v[i].s)>-1e-9)tail--;
            while(front<tail&&(ans[front]-v[i].s)*(v[i].t-v[i].s)>-1e-9)front++;
            if(fabs(q[tail].arg+pi-v[i].arg)<1e-6)return 0;
            ans[tail]=v[i]&q[tail];q[++tail]=v[i];
        }
    while(front<tail&&(ans[tail-1]-q[front].s)*(q[front].t-q[front].s)>-1e-9)tail--;
    ans[tail]=q[tail]&q[front];
    for(int i=front;i<=tail;i++)ans[i-front]=ans[i];
    return tail-front+1;
}
int n;
inline bool ok(double mid)
{
    Point dir,te;
    double dis;
    for(int i=0;i<n;i++)
    {
        te=po[i+1]-po[i];
        dis=te/Point(0,0);
        dir=Point(-te.y,te.x);
        te=dir/dis*mid;
        l[i]=Line(po[i]+te,po[i+1]+te);
    }
    return halfplaneintersection(l,n,hull)<3;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&po[i].x,&po[i].y);
    po[n]=po[0];
    double l=0.0,r=1e7,mid;
    while(r-l>1e-4)
    {
        mid=(l+r)/2;
        if(ok(mid))r=mid;
        else l=mid;
    }
    printf("%.8f\n",r);
    return 0;
}