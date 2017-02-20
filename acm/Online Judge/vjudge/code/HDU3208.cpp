#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


const long long inf=1e18+300;
const long long why=1ll<<31;
long long f[70];
long long pow_mod(long long a,long long b)
{
    long long c=1;
    double d;
    while(b)
    {
        if(b&1)
        {
            d=1.0*c*a;
            if(d>=inf)return -1;
            c*=a;
        }
        b>>=1;
        d=1.0*a*a;
        if(d>=inf&&b)return -1;
        a*=a;
    }
    return c;
}
long long cal(long long x)
{
    f[1]=x-1;
    int z;
    for(int i=2;;i++)
    {
        long long c=pow(x,1.0/i);
        while(1)
        {
            long long h=pow_mod(c,i);
            if(h==-1)break;
            else if(h>x)break;
            c++;
        }
        f[i]=c-2;
        z=i;
        if(c==2)break;
    }
    for(int i=z;i>0;i--)
        for(int j=1;j<i;j++)
            if(i%j==0)f[j]-=f[i];
    long long sum=0;
    for(int i=1;i<=z;i++)
        sum+=i*f[i];
    return sum;
}
int main()
{
    //freopen("1.txt","r",stdin);
    long long a,b;
    while(scanf("%I64d%I64d",&a,&b)&&a&&b)
        printf("%I64d\n",cal(b)-cal(a-1));
    return 0;
}
