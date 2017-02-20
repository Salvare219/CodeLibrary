#include<bits/stdc++.h>
using namespace std;


int sgn(double x)
{
    return fabs(x)<1e-5?0:(x>0.0?1:-1);
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
    double arg(){return atan2(y,x);}
    bool operator==(const Point&a)const{return sgn(x-a.x)==0&&sgn(y-a.y)==0;}
}p[200];
inline Point line_cro(Point p1,Point p2,Point p3,Point p4)
{
    return (p2-p1)*((p1-p3)*(p3-p4))/((p1-p2)*(p3-p4))+p1;
}
const double pi=acos(-1.0);
Point ans;
int n,o;
double ph[200];
void solv(Point c)
{
    for(int z=0;z<n;z++)
    {
        ph[z]=(p[z]-c).arg();
        if(sgn(ph[z])<=0)ph[z]+=pi;
    }
    sort(ph,ph+n);
    int f=1;
    for(int z=0;z<n;z+=2)
        if(sgn(ph[z]-ph[z+1])!=0)
        {
            f=0;
            break;
        }
    for(int z=1;z<n;z+=2)
        if(sgn(ph[z]-ph[z+1])==0)
        {
            f=0;
            break;
        }
    if(f)
    {
        if(o==0)o=1,ans=c;
        else
        {
            if(ans==c);
            else o=2;
        }
    }
}
int main()
{
    freopen("center.in","r",stdin);
    freopen("center.out","w",stdout);
    scanf("%d",&n);n<<=1;
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i=2;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(sgn((p[0]-p[i])*(p[1]-p[j]))!=0)
            {
                Point c=line_cro(p[0],p[i],p[1],p[j]);
                solv(c);
            }
            if(sgn((p[0]-p[j])*(p[1]-p[i]))!=0)
            {
                Point c=line_cro(p[0],p[j],p[1],p[i]);
                solv(c);
            }
            if(sgn((p[0]-p[1])*(p[i]-p[j]))!=0)
            {
                Point c=line_cro(p[0],p[1],p[i],p[j]);
                solv(c);
            }
        }
    if(o==0)puts("Impossible");
    else if(o>1)puts("Ambiguity");
    else
    {
        printf("Center of the universe found at (%.11f, %.11f)\n",ans.x,ans.y);
    }
    return 0;
}
