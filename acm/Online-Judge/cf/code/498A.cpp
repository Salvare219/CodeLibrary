#include <bits/stdc++.h>
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
}A,B,C[2];
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
inline bool cross(Point p0,Point p1,Point p2,Point p3)
{
    return sgn(((p1-p0)*(p2-p0))*((p1-p0)*(p3-p0)))<0 && sgn(((p3-p2)*(p0-p2))*((p3-p2)*(p1-p2)))<0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
    int n;scanf("%d",&n);
    double a,b,c;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        if(sgn(b)==0)
        {
            C[0]=Point((-b*1000001+c)/(-a),-1000001);
            C[1]=Point((b*1000001+c)/(-a),1000001);
        }
        else
        {
            C[0]=Point(-1000001,(-a*1000001+c)/(-b));
            C[1]=Point(1000001,(a*1000001+c)/(-b));
        }
        if(cross(A,B,C[0],C[1]))
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}

