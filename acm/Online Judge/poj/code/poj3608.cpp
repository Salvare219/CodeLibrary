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
    return fabs(x)<1e-9?0:(x>0.0?1:-1);
}
struct Point
{
    double x,y;
    Point(double a=0,double b=0){x=a;y=b;}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    double operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    double operator%(const Point&a)const{return x*a.x+y*a.y;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    bool operator<(const Point&a)const
    {
        double temp=*this*a;
        return sgn(temp)==1||(sgn(temp)==0&&sgn(a.x*a.x+a.y*a.y-x*x-y*y)==1);
    }
}po1[10050],po2[10050],hull1[10050],hull2[10050];
int convex(Point h[],int n,Point ans[],int &k)
{
    for(int i=1;i<n;i++)
        if(sgn(h[0].y-h[i].y)==1||(sgn(h[0].y-h[i].y)==0&&sgn(h[0].x-h[i].x)==1))swap(h[0],h[i]);
    Point sta=h[0];
    for(int i=0;i<n;i++)h[i]=h[i]-sta;
    sort(h+1,h+n);k=min(2,n);
    for(int i=0;i<n;i++)h[i]=h[i]+sta;
    ans[0]=h[0];ans[1]=h[1];
    for(int i=2;i<n;i++)
    {
        while(k>1&&sgn((ans[k-1]-ans[k-2])*(h[i]-ans[k-2]))!=1)k--;
        ans[k++]=h[i];
    }
}
inline double p2l_dist(Point p1,Point p2,Point p3)
{
    Point d=Point(-(p3-p2).y,(p3-p2).x);
    if(sgn(d*(p2-p1))==sgn(d*(p3-p1)))return min(p1/p2,p1/p3);
    else
    {
        d=d/(d/Point(0,0));
        return fabs((p3-p1)%d);
    }
}
inline double seg_dist(Point p1,Point p2,Point p3,Point p4)
{
    double t1=min(p2l_dist(p1,p3,p4),p2l_dist(p2,p3,p4));
    double t2=min(p2l_dist(p3,p1,p2),p2l_dist(p4,p1,p2));
    return min(t1,t2);
}
double convex_dist(Point h1[],int n,Point h2[],int m)
{
    int p1=0,p2=0,tp;
    for(int i=1;i<n;i++)
        if(sgn(h1[p1].y-h1[i].y)>0)p1=i;
    for(int i=1;i<m;i++)
        if(sgn(h2[p2].y-h2[i].y)<0)p2=i;
    h1[n]=h1[0];h2[m]=h2[0];tp=p1;
    double ans=1e10;
    do
    {
        ans=min(ans,seg_dist(h1[p1],h1[p1+1],h2[p2],h2[p2+1]));
        ans=min(ans,seg_dist(h1[p1],h1[p1+1],h2[p2>0?p2-1:m-1],h2[p2]));
        ans=min(ans,seg_dist(h1[p1>0?p1-1:n-1],h1[p1],h2[p2],h2[p2+1]));
        ans=min(ans,seg_dist(h1[p1>0?p1-1:n-1],h1[p1],h2[p2>0?p2-1:m-1],h2[p2]));
        while(sgn((h2[p2+1]-h2[p2])*(h1[p1+1]-h1[p1]))<0)
        {
            p2==m-1?p2=0:p2++;
            ans=min(ans,seg_dist(h1[p1],h1[p1+1],h2[p2],h2[p2+1]));
            ans=min(ans,seg_dist(h1[p1],h1[p1+1],h2[p2>0?p2-1:m-1],h2[p2]));
            ans=min(ans,seg_dist(h1[p1>0?p1-1:n-1],h1[p1],h2[p2],h2[p2+1]));
            ans=min(ans,seg_dist(h1[p1>0?p1-1:n-1],h1[p1],h2[p2>0?p2-1:m-1],h2[p2]));
        }
        p1==n-1?p1=0:p1++;
    }while(p1!=tp);
    return ans;
}
int main()
{
    
    int n,m,k1,k2;while(scanf("%d%d",&n,&m))
{
if(n==0)break;
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&po1[i].x,&po1[i].y);convex(po1,n,hull1,k1);
    for(int i=0;i<m;i++)
        scanf("%lf%lf",&po2[i].x,&po2[i].y);convex(po2,m,hull2,k2);
    printf("%.5f\n",convex_dist(hull1,k1,hull2,k2));}
    return 0;
}
