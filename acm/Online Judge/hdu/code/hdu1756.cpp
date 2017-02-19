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
    double arg(){return atan2(y,x);}
}po[200];
const double eps = 1e-8;
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
double const maxn=1e5;
bool inpol(Point pol[],int n,Point p1)
{
    int cnt=0,i;
    Point p2;pol[n]=pol[0];
    for(i=n;i>0;i--)
        if(sgn((pol[i-1]-p1)*(pol[i]-p1))==0&&sgn((pol[i-1]-p1)%(pol[i]-p1))!=1)
            return 1;
    while(i<n)
    {
        p2=Point(rand()+maxn,rand()+maxn);
        for(i=0;i<n;i++)
        {
            if(!sgn((p2-p1)*(pol[i]-p1))){cnt=0;break;}
            if(sgn((p2-pol[i])*(pol[i+1]-pol[i]))*sgn((p1-pol[i])*(pol[i+1]-pol[i]))==-1
               &&sgn((p2-p1)*(pol[i+1]-p1))*sgn((p2-p1)*(pol[i]-p1))==-1)cnt++;
        }
    }
    return cnt&1;
}
int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        scanf("%d",&m);
        double x,y;
        while(m--)
        {
            scanf("%lf%lf",&x,&y);
            if(inpol(po,n,Point(x,y)))puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
