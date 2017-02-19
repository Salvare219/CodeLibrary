#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


#include<complex>
typedef complex<double> point;
point circumcenter(point &a,point &b,point &c)
{
    double a1=b.real()-a.real(),b1=b.imag()-a.imag(),c1 =(a1*a1+b1*b1)/2;
    double a2=c.real()-a.real(),b2=c.imag()-a.imag(),c2 =(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    return point(a.real()+(c1*b2-c2*b1)/d,a.imag()+(a1*c2-a2*c1)/d);
}
point a[505],c;
double r;
int n;
void min_circle()
{
    r=0.0;c=a[0];
    for(int i=1;i<n;i++)
        if(abs(a[i]-c)>r)
        {
            c=a[i];r=0.0;
            for(int j=0;j<i;j++)
                if(abs(a[j]-c)>r)
                {
                    c=a[i]+a[j];
                    c=point(c.real()/2,c.imag()/2);
                    r=abs(a[j]-c);
                    for(int k=0;k<j;k++)
                        if(abs(a[k]-c)>r)
                        {
                            c=circumcenter(a[i],a[j],a[k]);
                            r=abs(a[k]-c);
                        }
                }
        }
}
int main()
{
    double x,y;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            a[i]=point(x,y);
        }
        min_circle();
        printf("%.2lf %.2lf %.2lf\n",c.real(),c.imag(),r);
    }
    return 0;
}
