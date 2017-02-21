#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double a[10005],b[10005],c[10005],d[10005];
pair<double,double>p[10005];
pair<double,int>h[10005];
int bit[10005],n;
void updat(int x)
{
    while(x<=n)bit[x]++,x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",a+i,b+i,c+i,d+i),bit[i+1]=0;
        double l,r,k;
        scanf("%lf%lf",&l,&r);
        for(int i=0;i<n;i++)
        {
            k=(d[i]-b[i])/(c[i]-a[i]);
            p[i]=make_pair(k*(l-c[i])+d[i],k*(r-c[i])+d[i]);
        }
        sort(p,p+n);
        for(int i=0;i<n;i++)h[i]=make_pair(p[i].second,i+1);
        long long ans=0;sort(h,h+n);
        for(int i=n-1;i>-1;i--)
            ans+=query(h[i].second),updat(h[i].second);
        printf("%lld\n",ans);
    }
    return 0;
}
