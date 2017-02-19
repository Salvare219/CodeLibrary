#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long d,b,t,p;
long long ok(long long mid)
{
    double c=1.0*b*t/d-t;
    double tt=1.0*mid/d;
    return ceil(c/tt);
}
int main()
{
    freopen("video.in","r",stdin);
    freopen("video.out","w",stdout);
    scanf("%I64d%I64d%I64d%I64d",&d,&b,&t,&p);
    long long l=0,r=p*d,mid;
    long long ans=ok(r);
    while(r>l)
    {
        mid=(l+r)/2;
        if(ok(mid)==ans)r=mid;
        else l=mid+1;
    }
    printf("%I64d\n",l);
    return 0;
}
