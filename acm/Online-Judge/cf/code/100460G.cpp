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
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
    bool operator==(const Point&a)
    {
        if(sgn(a.x-x)==0&&sgn(a.y-y)==0)
            return 1;
        else
            return 0;
    }
}po[65],f[50],ll[555];
bool cir_cross(Point p1,double r1,Point p2,double r2,Point ans[])
{
    double d=p1/p2,cosa,sina;
    if(sgn(d-r1-r2)==1||sgn(fabs(r1-r2)-d)==1)return 0;
    cosa=(r1*r1+d*d-r2*r2)/(2*r1*d);
    sina=sqrt(max(0.0,1.0-cosa*cosa));
    Point ve=(p2-p1)*r1/d;
    ans[0]=p1+Point(ve.x*cosa+ve.y*sina,ve.y*cosa-ve.x*sina);
    ans[1]=p1+Point(ve.x*cosa-ve.y*sina,ve.y*cosa+ve.x*sina);
    return 1;
}
double r;
int main()
{


    scanf("%lf",&r);
    for(int i=0;i<3;i++)
        scanf("%lf%lf",&po[i].x,&po[i].y);

    int k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(i!=j)
            {
                if(cir_cross(po[i],r,po[j],r,ll))
                {
                    f[k++]=ll[0];
                    f[k++]=ll[1];
                }
            }
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            if(i!=j)
            {
                Point z=(f[i]+f[j])/2;
                double d1=z/po[0],d2=z/po[1],d3=z/po[2];
                if(sgn(r-d1)>=0&&sgn(r-d2)>=0&&sgn(r-d3)>=0)
                {
                    puts("YES");
                    printf("%.8f %.8f\n",z.x,z.y);
                    return 0;
                }
            }
    puts("NO");
    return 0;
}

