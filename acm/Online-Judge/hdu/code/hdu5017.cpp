#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int sgn(double x)
{
    return fabs(x)<1e-13?0:(x>0.0?1:-1);
}
double cal(double l,double r,double a,double b,double c,double d)
{
    double mid;
    for(int i=0;i<500;i++)
    {
        mid=(l+r)/2;
        if(sgn(((a*mid+b)*mid+c)*mid+d)<0)l=mid;
        else r=mid;
    }
    return l;
}
double cal2(double l,double r,double a,double b,double c,double d)
{
    double mid;
    for(int i=0;i<500;i++)
    {
        mid=(l+r)/2;
        if(sgn(((a*mid+b)*mid+c)*mid+d)>0)l=mid;
        else r=mid;
    }
    return l;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    double a,b,c,d,e,f;
    while(~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f))
    {
        double a11=-a,  a12=-f/2,a13=-e/2;
        double a21=-f/2,a22=-b,  a23=-d/2;
        double a31=-e/2,a32=-d/2,a33=-c;
        double aa=1,bb=(a11+a22+a33),cc=(a11*a22+a11*a33+a22*a33-a13*a31-a23*a32-a12*a21);
        double dd=a11*a22*a33+a12*a23*a31+a13*a21*a32-a13*a22*a31-a11*a23*a32-a12*a21*a33;
        double del=4*bb*bb-12*aa*cc;
        double x1=(-2*bb-sqrt(del))/6/aa,x2=(-2*bb+sqrt(del))/6/aa;
        double ans1=cal(-1e8,x1,aa,bb,cc,dd);
        double ans2=cal2(x1,x2,aa,bb,cc,dd);
        double ans3=cal(x2,1e8,aa,bb,cc,dd);
        printf("%.8f\n",sqrt(1.0/max(ans1,max(ans2,ans3))));
    }
    return 0;
}
