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
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
}po[1005];
double ans[1005],ans2[1005];
double r[1005];
const double eps=1e-7;
const double pi=acos(-1.0);
inline int sgn(double x)
{return fabs(x)<eps?0:(x>0.0?1:-1);}
pair<double,bool>arg[2005];
void cir_union(Point c[],double r[],int n)
{
    double d,p1,p2,p3;
    for(int i=0;i<n;i++)
    {
        int k=0,cnt=1;
        for(int j=0;j<n;j++)
            if(i!=j&&sgn((d=c[i]/c[j])-r[i]-r[j])<=0)
            {
                if(sgn(d+r[i]-r[j])<=0)cnt++;
                else if(sgn(d+r[j]-r[i])<=0);
                else
                {
                    p3=acos((r[i]*r[i]+d*d-r[j]*r[j])/(2.0*r[i]*d));
                    p2=atan2(c[j].y-c[i].y,c[j].x-c[i].x);
                    p1=p2-p3;p2=p2+p3;
                    if(sgn(p1+pi)==-1)p1+=2*pi,cnt++;
                    if(sgn(p2-pi)==1)p2-=2*pi,cnt++;
                    arg[k++]=make_pair(p1,0);arg[k++]=make_pair(p2,1);
                }
            }
        if(k)
        {
            sort(arg,arg+k);
            p1=arg[k-1].first-2*pi;
            p3=r[i]*r[i];
            for(int j=0;j<k;j++)
            {
                p2=arg[j].first;
                ans[cnt]+=(c[i]+Point(cos(p1),sin(p1))*r[i])*(c[i]+Point(cos(p2),sin(p2))*r[i]);
                ans2[cnt]+=(p2-p1-sin(p2-p1))*p3;
                p1=p2;
                arg[j].second?cnt--:cnt++;
            }
        }
        else ans2[cnt]+=2*pi*r[i]*r[i];
    }
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf%lf",&po[i].x,&po[i].y,r+i);
    cir_union(po,r,n);
    for(int i=1;i<=n;i++)
        ans[i]=fabs(ans[i])+ans2[i];
    for(int i=1;i<=n;i++)
        printf("[%d] = %.3f\n",i,(ans[i]-ans[i+1])*0.5);
    return 0;
}
