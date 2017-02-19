#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    long long x,y;
    Point(long long a=0,long long b=0){x=a;y=b;}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    bool operator<(const Point&a)const
    {
        long long temp=*this*a;
        return temp>0||(temp==0&&x*x+y*y<a.x*a.x+a.y*a.y);
    }
}po[1005],hull[1005];
int convex(Point h[],int n,Point ans[],int &k)
{
//    for(int i=1;i<n;i++)
//        if(h[0].y>h[i].y||(h[0].y==h[i].y&&h[0].x>h[i].x))swap(h[0],h[i]);
    Point sta=h[0];
    for(int i=0;i<n;i++)h[i]=h[i]-sta;
    sort(h+1,h+n);k=min(2,n);
    for(int i=0;i<n;i++)h[i]=h[i]+sta;
    ans[0]=h[0];ans[1]=h[1];
    for(int i=2;i<n;i++)
    {
        while(k>1&&(ans[k-1]-ans[k-2])*(h[i]-ans[k-2])<=0)k--;
        ans[k++]=h[i];
    }
}
int main()
{
    int n=0,k;
    while(~scanf("%lld%lld",&po[n].x,&po[n].y))n++;
    convex(po,n,hull,k);
    for(int i=0;i<k;i++)
        printf("(%lld,%lld)\n",hull[i].x,hull[i].y);
    return 0;
}
