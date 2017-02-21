#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
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
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    long long operator%(const Point&a)const{return x*a.x+y*a.y;}
    bool operator==(const Point&a)const{return a.x==x&&a.y==y;}
}lib[5000];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    double ans=0;
    Point p[6],fin[6];
    p[0]=Point(0,0);
    p[1]=Point(n,m);
    int c=0;
    for(int i=0;i<=n;i++)
        lib[c++]=Point(i,0);
    for(int i=1;i<=m;i++)
        lib[c++]=Point(n,i);
    for(int i=n-1;i>=0;i--)
        lib[c++]=Point(i,m);
    for(int i=m-1;i>0;i--)
        lib[c++]=Point(0,i);
    for(int i=0;i<c;i++)
        for(int j=0;j<c;j++)
        {
            int g=0;
            p[2]=lib[i];
            p[3]=lib[j];
            if(p[3]==p[0])g=1;
            if(p[3]==p[1])g=1;
            if(p[2]==p[0])g=1;
            if(p[2]==p[1])g=1;
            if(p[3]==p[2])g=1;
            if(g==0)
            {
                double t=0;
                t=(p[0]/p[1])+(p[1]/p[2])+(p[2]/p[3]);
                if(t>ans)
                {
                    ans=t;
                    fin[0]=p[0];
                    fin[1]=p[1];
                    fin[2]=p[2];
                    fin[3]=p[3];
                }
                t=(p[0]/p[1])+(p[1]/p[2])+(p[0]/p[3]);
                if(t>ans)
                {
                    ans=t;
                    fin[0]=p[2];
                    fin[1]=p[1];
                    fin[2]=p[0];
                    fin[3]=p[3];
                }
                t=(p[0]/p[1])+(p[1]/p[3])+(p[0]/p[2]);
                if(t>ans)
                {
                    ans=t;
                    fin[0]=p[3];
                    fin[1]=p[1];
                    fin[2]=p[0];
                    fin[3]=p[2];
                }
            }
        }
    for(int i=0;i<4;i++)
        printf("%I64d %I64d\n",fin[i].x,fin[i].y);
    return 0;
}


