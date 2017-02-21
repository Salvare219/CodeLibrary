#include<bits/stdc++.h>
using namespace std;


struct Point
{
    int x,y;
    Point(int a=0.0,int b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const int&a)const{return Point(x*a,y*a);}
    Point operator/(const int&a)const{return Point(x/a,y/a);}
    int operator*(const Point&a)const{return x*a.y-y*a.x;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    int operator%(const Point&a)const{return x*a.x+y*a.y;}
}a,b,c;
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
    int v1,v3,x,y;
    double cos;
    double t1,t2,t3;
    scanf("%lf%d",&cos,&v1);
    cos/=60;
    scanf("%d%*c%d",&x,&y);
    t2=x*60+y;
    scanf("%d%*c%d",&x,&y);
    t2=x*60+y+t2-9*60;
    t2/=60;
    scanf("%d",&v3);
    t1=((a/c)+(c/b))/v1+cos;
    Point d1=a-c,d2=b-c;
    if((d1*d2)==0&&(d1%d2)<0)
        t3=(a/b)/v3+cos;
    else
        t3=(a/b)/v3;

    //printf("%f %f %f\n",t1,t2,t3);

    if(t1<t2&&t1<t3)puts("Alex");
    else if(t2<t1&&t2<t3)puts("Dmitry");
    else puts("Petr");
    return 0;
}

