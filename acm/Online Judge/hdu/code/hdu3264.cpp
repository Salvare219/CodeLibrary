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
    Point(){}
    Point(double a,double b){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
}po[30];
double r[30];
const double pi=acos(-1.0);
int n;
double cir_inter(Point a,double ra,Point b,double rb)
{
    double d=a/b;
    if(ra>rb)swap(ra,rb);
    if(ra+rb-d<1e-8)return 0.0;
    if(d+ra-rb<1e-8)return 2*pi*ra*ra;
    double p1=2*acos((ra*ra+d*d-rb*rb)/(2.0*ra*d));
    double p2=2*acos((rb*rb+d*d-ra*ra)/(2.0*rb*d));
    return ((p1-sin(p1))*ra*ra+(p2-sin(p2))*rb*rb)*0.5;
}
bool ok(int i,double mid)
{
    for(int j=0;j<n;j++)
        if(j!=i)
        {
            double sum=cir_inter(po[i],mid,po[j],r[j]);
            if(pi*r[j]*r[j]-2*sum>1e-5)return 0;
        }
    return 1;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&po[i].x,&po[i].y,r+i);
        double ans=1e10;
        if(n==1)ans=sqrt(2.0)/2*r[0];
        else 
        {
            for(int i=0;i<n;i++)
            {
                double l=r[i],rr=50000.0,mid;
                while(rr-l>1e-6)
                {
                    mid=(l+rr)/2;
                    if(ok(i,mid))rr=mid;
                    else l=mid;
                }
                ans=min(ans,rr);
            }
        }
        printf("%.4f\n",ans);
    }
    return 0;
}