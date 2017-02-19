#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

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
}a[9],po[9];
pair<double,int>sum[500];
int ans[500];
int sgn(double x)
{
    return fabs(x)<1e-4?0:(x>0.0?1:-1);
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
            scanf("%lf%lf",&a[j].x,&a[j].y);
        int c;scanf("%d",&c);
        double la=100.0/(a[0]/a[1]),lb=100.0/(a[2]/a[3]);
        for(int j=0;j<c;j++)
        {
            for(int k=0;k<4;k++)
                scanf("%lf%lf",&po[k].x,&po[k].y);
            double s=0.0;
            for(int k=2;k<4;k++)
                s+=(po[k]-po[0])*(po[k-1]-po[0]);
            sum[i].first+=fabs(s*la*lb);
        }
        sum[i].second=i;
    }
    sort(sum,sum+n);
    int cnt=1;
    ans[sum[0].second]=1;
    for(int i=1;i<n;i++)
        if(sgn(sum[i].first-sum[i-1].first)==0)
        {
            ans[sum[i].second]=cnt;
        }
        else
        {
            cnt++;
            ans[sum[i].second]=cnt;
        }
    printf("%d",ans[0]);
    for(int i=1;i<n;i++)
        printf(" %d",ans[i]);
    putchar(10);
    return 0;
}
