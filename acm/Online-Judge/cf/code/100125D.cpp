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
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
}a,b,c;
const double s2=sqrt(2.0);
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("deepest.in","r",stdin);
    freopen("deepest.out","w",stdout);
    int xi,yi,zi;
    double x,y,z;
    scanf("%d%d%d",&xi,&yi,&zi);
    x=xi;y=yi;z=zi;
    if(1ll*xi*xi+1ll*yi*yi==1ll*zi*zi)
    {
        puts("Single staircase");
    }
    else
    {
        c=Point(x,y);
        double d1=c/Point(0,0);
        a=Point(d1,0);b=Point(0,z);
        double d2=z-d1;
        c=a+Point(d2*0.5,d2*0.5);
        if(c.y<-1e-12)puts("Impossible");
        else
        {
            z=c.y;
            a=Point(x,y);
            c=a+a*(d2/(2*d1));
            printf("%.12f %.12f %.12f\n",c.x,c.y,z);
        }
    }
    return 0;
}
