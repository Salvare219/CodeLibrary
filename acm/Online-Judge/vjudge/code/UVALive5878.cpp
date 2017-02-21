#include<bits/stdc++.h>
using namespace std;


struct Point
{
    int x,y,g;
    Point(){}
    Point(int x_,int y_)
    {
        x=x_;y=y_;
        if(y>0)g=1;
        else
        {
            if(y==0&&x>0)g=1;
            else g=2;
        }
    }
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    int operator*(const Point&a)const{return x*a.y-y*a.x;}
    int operator%(const Point&a)const{return x*a.x+y*a.y;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    bool operator<(const Point&a)const
    {
        if(a.g==g)return *this*a>0;
        else return g<a.g;
    }
}p[500];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            p[i]=Point(x,y);
        }
        sort(p,p+n);
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            Point z=Point(0,0);
            for(int j=0;j<n;j++)
                if(p[i]*p[j]>0)
                    z=z+p[j];
                else if(p[i]*p[j]<0)
                    z=z-p[j];
                else
                {
                    if(p[i]%p[j]>0)
                        z=z-p[j];
                    else
                        z=z+p[j];
                }
            ans=max(ans,z/Point(0,0));
        }
        printf("%.3f\n",ans);
    }
	return 0;
}
