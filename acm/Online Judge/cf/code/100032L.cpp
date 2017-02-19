#include<bits/stdc++.h>
using namespace std;

const double p2=acos(-1)/2,eps=1e-9;
double a[100005],b[100005],c[100005];
bool s[100005];
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
int main()
{
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);
    int n,sn=0,i;
    double mn;
    for(scanf("%d",&n),i=0;i<n;i++)
        scanf("%lf",a+i);
    for(i=0,mn=p2;i<n;i++)
    {
        if(sgn(mn-fabs(a[i]-p2))>0)
            mn=fabs(a[i]-p2);
        b[i]=mn;
    }
    for(i=n,mn=p2;i--;)
    {
        if(sgn(mn-fabs(a[i]-p2))>0)
            mn=fabs(a[i]-p2);
        c[i]=mn;
    }
    for(i=0;i<n;i++)
    {
        if(sgn(a[i]-p2)>0)
        {
            if(sgn(a[i]-p2-b[i])<=0)
                s[i]=1,sn++;
        }
        else if(sgn(a[i]-p2)<0)
        {
            if(sgn(p2-a[i]-c[i])<=0)
                s[i]=1,sn++;
        }
        else
            s[i]=1,sn++;
    }
    printf("%d\n",sn);
    for(i=0;i<n;i++)
        if(s[i])
            printf("%d%c",i+1,--sn?' ':'\n');
    return 0;
}
