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
    long long operator/(const Point&a)const{return (a.x-x)*(a.x-x)+(a.y-y)*(a.y-y);}
    long long operator%(const Point&a)const{return x*a.x+y*a.y;}
}p1[200],p2[200];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        for(int i=0;i<n;i++)
            scanf("%lld%lld",&p1[i].x,&p1[i].y);
        for(int i=0;i<m;i++)
            scanf("%lld%lld",&p2[i].x,&p2[i].y);
        int f=0;
        for(int i=0;i<n&&!f;i++)
            for(int j=0;j<m&&!f;j++)
            {
                Point d=p2[j]-p1[i];
                int u1=0,d1=0,m1=0;
                for(int k=0;k<n;k++)
                    if((p1[k]-p1[i])*d>0)u1=1;
                    else if((p1[k]-p1[i])*d<0)d1=1;
                    else if((p1[i]-p1[k])%(p2[j]-p1[k])<0||p1[i]/p1[k]>p2[j]/p1[k])m1=1;
                if(m1==1)continue;
                if(u1==1&&d1==1)continue;
                int u2=0,d2=0,m2=0;
                for(int k=0;k<m;k++)
                    if((p2[k]-p1[i])*d>0)u2=1;
                    else if((p2[k]-p1[i])*d<0)d2=1;
                    else if((p1[i]-p2[k])%(p2[j]-p2[k])<0||p1[i]/p2[k]<p2[j]/p2[k])m2=1;
                if(m2==1)continue;
                if(u2==1&&d2==1)continue;
                if(u1==1&&u2==1)continue;
                if(d1==1&&d2==1)continue;
                f=1;
            }
        puts(f?"YES":"NO");
    }
    return 0;
}
