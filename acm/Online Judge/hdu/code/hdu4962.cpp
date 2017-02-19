#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


inline int sgn(double x)
{
    return fabs(x)<1e-9?0:(x>0.0?1:-1);
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

    bool operator<(const Point&a)const
    {
        return x<a.x;
    }
    bool operator==(const Point&a)const
    {
        return sgn(x-a.x)==0&&sgn(y-a.y)==0;
    }
}po[1005];
inline Point line_cro(const Point&p1,const Point&p2,const Point&p3,const Point&p4)
{
    return (p2-p1)*((p1-p3)*(p3-p4))/((p1-p2)*(p3-p4))+p1;
}
const double pi=acos(-1.0);
pair<double,int>pp[1005];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,l1,l2;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l1,&l2);
            po[i].x=l1;po[i].y=l2;
        }
        po[n]=po[0];
        Point z=Point(0,0),z2=Point(1000,0),z3=Point(-1005,0);
        int k=0;
        int ans=0,now=0;
        for(int i=0;i<n;i++)
            if(sgn(po[i].y-po[i+1].y)!=0)
            {
                Point c=line_cro(po[i],po[i+1],z,z2);
                int d=sgn((po[i]-c)%(po[i+1]-c));
                int e=sgn((po[i]-z3)*(po[i+1]-z3));
                if(d==0)
                    pp[k++]=make_pair(c.x,-e),now+=e;
                else if(d==-1)
                    pp[k++]=make_pair(c.x,-2*e),now+=2*e;
            }
        sort(pp,pp+k);
        ans=now;
        for(int i=0;i<k;)
        {
            int p=i;
            while(i<k&&sgn(pp[p].first-pp[i].first)==0)
                now+=pp[i++].second;
            ans=max(ans,now);
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
