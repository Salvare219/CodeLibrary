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
}po[55],c;
const double eps=1e-7;
inline int sgn(double x){return fabs(x)<eps?0:(x>0.0?1:-1);}
double cir_tri(Point c,double r,Point p1,Point p2)
{
    bool f=1;p1=p1-c;p2=p2-c;
    double sum=p1*p2,h,r1,r2,r3;
    if(sgn(sum)==0)return 0.0;
    if(sgn(sum)==-1)swap(p1,p2),f=0;
    r2=p1/Point(0,0);r3=p2/Point(0,0);
    r1=(p1%p2)/r2/r3;
    Point v,s=p2-p1,t1=Point(-s.y,s.x),t2=t1*(p1*(p2-p1))/(t1*(p2-p1));
    v=s/(p1/p2);h=t2.x*t2.x+t2.y*t2.y;
    if(sgn(r*r-h)!=1)sum=acos(r1)*r*r/2.0;
    else
    {
        h=sqrt(r*r-h);
        t1=t2-v*h;t2=t2+v*h;
        r2=(p1%t1)/(t1/Point(0,0))/r2;
        r3=(p2%t2)/(t2/Point(0,0))/r3;
        int d1,d2;
        d1=sgn(p1*t2)==1?sgn(p1*t1)==1:-1;
        d2=sgn(p2*t2)==1?sgn(p2*t1)==1:-1;
        if(d1*d2==1)sum=acos(r1)*r*r/2.0;
        else if(d1*d2==-1)sum=acos(r2)*r*r/2.0+acos(r3)*r*r/2.0+t1*t2/2.0;
        else if(d1!=0)sum=acos(r2)*r*r/2.0+t1*p2/2.0;
        else if(d2!=0)sum=p1*t2/2.0+acos(r3)*r*r/2.0;
        else sum=p1*p2/2.0;
    }
    return f?sum:-sum;
}
int main()
{
    double r;
    while(~scanf("%lf",&r))
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        po[n]=po[0];
        double area=0.0;
        for(int i=0;i<n;i++)area+=cir_tri(Point(0,0),r,po[i],po[i+1]);
        printf("%.2f\n",fabs(area));

    }
    return 0;
}