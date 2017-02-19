#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
struct Point
{
    double x,y;
    double ph;
    Point(double a=0.0,double b=0.0){x=a;y=b;ph=atan2(y,x);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
    double arg(){return atan2(y,x);}

    bool operator==(const Point&a)const
    {
        return sgn(ph-a.ph)==0;
    }
    bool operator<(const Point&a)const
    {
        return ph<a.ph;
    }
}po[555];
const double eps=1e-6;
double r1,r2;
int n,d;
const double pi=acos(-1.0);
double f(double x)
{
    Point dir=Point(cos(x),sin(x));
    Point te=Point(-dir.y,dir.x);
    Point a=te*1e10,b=te*-1e10;
    for(int i=0;i<n;i++)
    {
        if(sgn((po[i]-a)*dir)>=0)
        {
            a=po[i];
        }
        if(sgn(dir*(po[i]-b))>=0)
        {
            b=po[i];
        }
    }
    return min(fabs((b-a)*dir),1.0*d)/d;
}
double cal(double l,double r)
{
    double h=(r-l)/2;
    return h*(f(l)+4*f((l+r)/2)+f(r))/3;
}
double Cal(double l,double r)
{
    double mid=(l+r)/2;
    if(fabs(cal(l,r)-cal(l,mid)-cal(mid,r))<eps)return cal(l,r);
    return Cal(l,mid)+Cal(mid,r);
}
int main()
{
    int ti=1,t;
    scanf("%d",&t);
    while(t--)
    {
        double x,y;
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            po[i]=Point(x,y);
        }
        sort(po,po+n);
        n=unique(po,po+n)-po;
        printf("Case #%d: ",ti++);
        if(n==1)
        {
            puts("0.0000");
        }
        else
        {
            double th=pi/1000,sum=0;
            for(int i=0;i<1000;i++)
                sum+=f(i*th)*th;
            printf("%.4f\n",sum/pi);
        }
    }
    return 0;
}
