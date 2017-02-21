#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const double eps=1e-9;
int sgn(double x)
{
    return fabs(x)<eps?0:(x>0?1:-1);
}
struct Point
{
    double x,y;
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
}po[60],te[5];
double r[60];
inline bool operator<(const Point&a,const Point&b)
{return sgn(a.x-b.x)?a.x<b.x:(sgn(a.y-b.y)?a.y<b.y:0);}
bool cir_cross(Point p1,double r1,Point p2,double r2,Point ans[])
{
    double d=p1/p2,cosa,sina;
    if(sgn(d-r1-r2)==1||sgn(fabs(r1-r2)-d)==1) return 0;
    cosa=(r1*r1+d*d-r2*r2)/(2*r1*d);
    sina=sqrt(max(0.0,1.0-cosa*cosa));
    Point ve=(p2-p1)*r1/d;
    ans[0]=p1+Point(ve.x*cosa+ve.y*sina,ve.y*cosa-ve.x*sina);
    ans[1]=p1+Point(ve.x*cosa-ve.y*sina,ve.y*cosa+ve.x*sina);
    return 1;
}
int com[200];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
#include<set>
set<Point>s[60],ss;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;ss.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&po[i].x,&po[i].y,r+i),com[i]=i,s[i].clear();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(cir_cross(po[i],r[i],po[j],r[j],te))
                {
                    com[find(i)]=find(j);
                    s[i].insert(te[0]);
                    s[i].insert(te[1]);
                    s[j].insert(te[0]);
                    s[j].insert(te[1]);
                    ss.insert(te[0]);
                    ss.insert(te[1]);
                }
        int ans=1-ss.size();
        for(int i=0;i<n;i++)
        {
            ans+=s[i].size();
            if(com[i]==i)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}