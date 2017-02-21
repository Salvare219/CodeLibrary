#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const double eps=1e-8;
struct Point
{
    double x,y;
    Point(double a=0.0,double b=0.0){x=a;y=b;}
    Point operator-(Point a){return Point(x-a.x,y-a.y);}
    Point operator+(Point a){return Point(x+a.x,y+a.y);}
    Point operator/(double a){return Point(x/a,y/a);}
    Point operator*(double a){return Point(x*a,y*a);}
    bool operator==(Point a){return x==a.x&&y==a.y;}
    bool operator<(Point a){return x==a.x?y<a.y:x<a.x;}
    double amplit(){return sqrt(x*x+y*y);}
}po[105];
int n;
double dis(Point c)
{
    double sum=0.0;
    for(int i=0;i<n;i++)
        sum+=(po[i]-c).amplit();
    return sum;
}
double femat()
{
    Point c=Point(0,0),te;
    double step=1e8,ans=0,f;
    for(int i=0;i<n;i++)
        c=c+po[i];
    c=c/n;
    for(int i=0;i<n;i++)
        ans+=(po[i]-c).amplit();
    while(step>eps)
    {
        te=c;
        f=dis(te+Point(0,step));
        if(f<ans) c=te+Point(0,step),ans=f;
        f=dis(te+Point(0,-step));
        if(f<ans) c=te+Point(0,-step),ans=f;
        f=dis(te+Point(step,0));
        if(f<ans) c=te+Point(step,0),ans=f;
        f=dis(te+Point(-step,0));
        if(f<ans) c=te+Point(-step,0),ans=f;
        step/=2;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&po[i].x,&po[i].y);
    printf("%.f\n",femat());
    return 0;
}
