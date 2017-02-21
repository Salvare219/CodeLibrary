#include <bits/stdc++.h>
using namespace std;


struct Point
{
    long long x,y;
    Point(long long a=0.0,long long b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    long long operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    long long operator%(const Point&a)const{return x*a.x+y*a.y;}
}p[100050];
long long gcd(long long a,long long b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
long long cal(Point p0)
{
    long long a=abs(p0.x*2),b=abs(p0.y*2);
    long long g=gcd(a,b);
    a/=g;b/=g;
    if(a%2&&b%2)return (g+1)/2;
    else return 0;
}
int main()
{
    freopen("semi-cool.in","r",stdin);
    freopen("semi-cool.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&p[i].x,&p[i].y);
    long long s1=0,s2=0;p[n]=p[0];
    for(int i=0;i<n;i++)
    {
        s1+=(p[i]-p[0])*(p[i+1]-p[0]);
        s2+=cal(p[i+1]-p[i]);
    }
    s1=abs(s1);
    printf("%lld\n",(s1-s2)/2+s2);
    return 0;
}
