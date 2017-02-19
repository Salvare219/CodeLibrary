#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point_3
{
    double x,y,z;
    Point_3(double a=0,double b=0,double c=0){x=a;y=b;z=c;}
    Point_3 operator+(const Point_3&a)const{return Point_3(x+a.x,y+a.y,z+a.z);}
    Point_3 operator-(const Point_3&a)const{return Point_3(x-a.x,y-a.y,z-a.z);}
    Point_3 operator*(const double&a)const{return Point_3(x*a,y*a,z*a);}
    Point_3 operator/(const double&a)const{return Point_3(x/a,y/a,z/a);}
    Point_3 operator*(const Point_3&a)const{return Point_3(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);}
    double operator/(const Point_3&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y)+(a.z-z)*(a.z-z));}
    double operator%(const Point_3&a)const{return x*a.x+y*a.y+z*a.z;}
};
Point_3 rota(Point_3 p,Point_3 v, double arg)
{
    double rot[3][3],cs=cos(arg),si=sin(arg);
    rot[0][0]=cs+(1-cs)*v.x*v.x;
    rot[0][1]=(1-cs)*v.x*v.y-si*v.z;
    rot[0][2]=(1-cs)*v.x*v.z+si*v.y;
    rot[1][0]=(1-cs)*v.y*v.x+si*v.z;
    rot[1][1]=cs+(1-cs)*v.y*v.y;
    rot[1][2]=(1-cs)*v.y*v.z-si*v.x;
    rot[2][0]=(1-cs)*v.z*v.x-si*v.y;
    rot[2][1]=(1-cs)*v.z*v.y+si*v.x;
    rot[2][2]=cs+(1-cs)*v.z*v.z;
    return Point_3(p.x*rot[0][0]+p.y*rot[0][1]+p.z*rot[0][2],
                   p.x*rot[1][0]+p.y*rot[1][1]+p.z*rot[1][2],
                   p.x*rot[2][0]+p.y*rot[2][1]+p.z*rot[2][2]);
}
int main()
{
    Point_3 p,v,r;
    double ph;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&p.z,&v.x,&v.y,&v.z,&ph))
    {
        v=v/(v/Point_3(0,0,0));
        r=rota(p,v,ph);
        printf("%.3lf %.3lf %.3lf\n",r.x,r.y,r.z);
    }
    return 0;
}
