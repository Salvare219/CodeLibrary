#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double a,b,c,d,e;
double f(double x)
{
    return a*(x-b)*(x-b)+c-d*x-e;
}
const int MAXREPT=10;
const double eps=1e-1;
double y[MAXREPT];
double Romberg(double aa, double bb)
{
    int m,n;
    double h,x,s,q,ep,p;
    h=bb-aa;
    y[0]=h*(f(aa)+f(bb))/2.0;
    m=n=1;ep=eps+1.0;
    while ((ep > eps) && (m < MAXREPT))
    {
        p=0.0;
        for(int i=0;i<n;i++)
            x=aa+(i+0.5)*h,p+=f(x);
        p=(y[0]+h*p)/2.0;s=1.0;
        for(int k=1;k<=m;k++)
        {
            s*=4.0;
            q=(s*p-y[k-1])/(s-1.0);
            y[k-1]=p;p=q;
        }
        p=fabs(q-y[m-1]);
        y[m++]=q;n<<=1;h/=2.0;
    }
    return q;
}
struct p
{double x,y;}po[5];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<3;i++)
            scanf("%lf%lf",&po[i].x,&po[i].y);
        b=po[0].x;c=po[0].y;
        a=(po[1].y-c)/(po[1].x-b)/(po[1].x-b);
        d=(po[2].y-po[1].y)/(po[2].x-po[1].x);
        e=po[1].y-d*po[1].x;
        printf("%.2f\n",Romberg(po[1].x,po[2].x));
    }
    return 0;
}
