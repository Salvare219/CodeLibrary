#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const double pi=acos(-1.0);
double H,R,D1,H1,D2,H2,D,N;
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
double cal(double hx,double hy,double res)
{
    double hz=(N*N*N+pi*R*R*hy)/(pi*R*R);
    if(sgn(hz-res)>=0)hz=res;
    if(sgn(hz-hx-N)>=0)
    {
        return 0;
    }
    else
    {
        double hz=(pi*R*R*hy-N*N*hx)/(pi*R*R-N*N);
        if(sgn(hz-res)>=0)hz=res;
        return N+hx-hz;
    }
}
bool ok(double mid)
{
    if(sgn(mid-H1)>=0)
    {
        double hh=cal(mid-H1,H2,H-H1);
        return sgn(N*N*N*D-(N-hh)*N*N*D2)>=0;
    }
    else
    {
        double hh1=cal(mid,H1,H);
        double hh2=cal(mid,H1+H2,H);
        return sgn(N*N*N*D-(hh1-hh2)*N*N*D2-(N-hh1)*N*N*D1)>=0;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&H,&R,&D1,&H1,&D2,&H2,&D,&N);
    double l=0,r=H1+H2,mid;
    for(int i=0;i<100000;i++)
    {
        mid=(l+r)/2;
        if(ok(mid))r=mid;
        else l=mid;
    }
    double hh=cal(r,H1+H2,H),ans;
    if(sgn(hh)==0)
    {
        ans=(pi*R*R*(H1+H2)+N*N*N)/(pi*R*R);
        ans=min(ans,H);
    }
    else
    {
        ans=r+N-hh;
    }
    printf("%.10f\n",ans);
    return 0;
}
