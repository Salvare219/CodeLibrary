#include<bits/stdc++.h>
using namespace std;


int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
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
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    bool operator<(const Point&a)const
    {
        double temp=*this*a;
        return sgn(temp)==1||(sgn(temp)==0&&sgn(a.x*a.x+a.y*a.y-x*x-y*y)==1);
    }
}po[1000005],hul[300005];
void convex(Point h[],int n,Point ans[],int &k)
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
int main()
{
    int n,k;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        convex(po,n,hul,k);
        int p1=1,p2=2;
        hul[k]=hul[0];
        double ans=0.0;
        for(int i=0;i<k;i++)
        {
            while(sgn((hul[p1]-hul[i])*(hul[p2+1]-hul[i])-(hul[p1]-hul[i])*(hul[p2]-hul[i]))>0)
                p2==k-1?p2=0:p2++;
            while(sgn((hul[p1+1]-hul[i])*(hul[p2]-hul[i])-(hul[p1]-hul[i])*(hul[p2]-hul[i]))>0)
                p1==k-1?p1=0:p1++;
            ans=max(ans,(hul[p1]-hul[i])*(hul[p2]-hul[i]));
        }
        printf("%.2f\n",ans*0.5);
    }
    return 0;
}
