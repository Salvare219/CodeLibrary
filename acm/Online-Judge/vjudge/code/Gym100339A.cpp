#include<bits/stdc++.h>
using namespace std;


struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
}a,b,p2[10055];
const double pi=acos(-1.0);
inline Point rota(Point p0,Point p1,double deg)
{
    Point n=p1-p0;
    return p0+Point(n.x*cos(deg)+n.y*sin(deg),n.y*cos(deg)-n.x*sin(deg));
}
double l2[10055];
double d,r,u,v;
const int f1=30;
const int f2=7005;
inline double cal(const Point&c)
{
    double ans=1e40;
    for(int j=1;j<=f2;j++)
    {
        double dis=(c/p2[j]/v)+l2[j];
        if(dis<ans)
            ans=dis;
    }
    return ans;
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("bike.in","r",stdin);
    freopen("bike.out","w",stdout);
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&d,&r,&a.x,&a.y,&b.x,&b.y,&u,&v);
    double ans=1e40;
    double delt1=2*pi/f1;
    double delt2=2*pi/f2;
    p2[1]=b;
    for(int i=2;i<=f2;i++)
        p2[i]=rota(Point(0,d),p2[i-1],delt2);
    double d1=r/u;
    double d2=delt2*r/u;
    for(int i=1;i<=f2;i++)
        l2[i]=d2*min(i-1,f2-i+1);
    for(int i=1;i<=f1;i++)
    {
        double l=(i-1)*delt1,r=i*delt1,m1,m2,t1,t2;
        int cnt=100;
        while(cnt--)
        {
            m1=(2*l+r)/3.0;
            m2=(l+2*r)/3.0;
            t1=cal(rota(Point(0,0),a,m1))+d1*min(m1,2*pi-m1);
            t2=cal(rota(Point(0,0),a,m2))+d1*min(m2,2*pi-m2);
            if(t1<t2)r=m2,ans=min(ans,t1);
            else l=m1,ans=min(ans,t2);
        }
    }
    printf("%.10f\n",ans);
    return 0;
}
