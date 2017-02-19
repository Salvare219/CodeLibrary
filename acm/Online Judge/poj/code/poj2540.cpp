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
    int front=0,tail=0;
    sort(v,v+n);q[0]=v[0];
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
int main()
{
    char s[10];
    bool f=0;
    int k=4;
    Point p=Point(0.0,0.0),p1,t1,t2,mid;
    l[0]=Line(Point(0,0),Point(10,0));
    l[1]=Line(Point(10,0),Point(10,10));
    l[2]=Line(Point(10,10),Point(0,10));
    l[3]=Line(Point(0,10),Point(0,0));
    while(~scanf("%lf%lf%s",&p1.x,&p1.y,s))
    {
        if(f)
        {
            puts("0.00");
            continue;
        }
        mid=(p1+p)/2;
        t1=p1-mid;t2=p-mid;
        swap(t1.x,t1.y);swap(t2.x,t2.y);
        t1.x=-t1.x;t2.x=-t2.x;
        t1=t1+mid;t2=t2+mid;
        if(s[0]=='C') l[k++]=Line(t2,t1);
        else if(s[0]=='H') l[k++]=Line(t1,t2);
        else
        {
            f=1;
            puts("0.00");
            continue;
        }
        int c=halfplaneintersection(l,k,hull);
        double area=0.0;
        for(int i=1;i<c;i++)
            area+=(hull[i]-hull[0])*(hull[i-1]-hull[0]);
        printf("%.2f\n",fabs(area)/2);
        p=p1;
    }
    return 0;
}
