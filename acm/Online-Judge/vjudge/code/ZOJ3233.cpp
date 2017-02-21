#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


long long gcd(long long a,long long b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
long long f[50];
long long g;
int n,m;
const long long inf=1e18+300;
long long cal(long long c)
{
    long long ans=0;
    for(int i=1;i<(1<<n);i++)
    {
        long long sum=0;
        int cnt=0;
        for(int j=i;j;j&=(j-1))
        {
            int h=__builtin_ctz(j);
            if(sum==0)sum=f[h];
            else
            {
                long long d=gcd(sum,f[h]);
                double ff=1.0*sum*f[h]/d;
                if(ff>=inf)
                {
                    sum=-1;
                    break;
                }
                else sum=sum/d*f[h];
            }
            cnt++;
        }
        if(sum!=-1)
        {
            long long how=c/sum;
            if(g!=-1)
            {
                long long d=gcd(sum,g);
                double zz=1.0*sum*g/d;
                if(zz>=inf);
                else
                {
                    d=sum/d*g;
                    how-=c/d;
                }
            }
            if(cnt&1)ans+=how;
            else ans-=how;
        }
    }
    return ans;
}
int main()
{
    long long a,b;
    while(scanf("%d%d%lld%lld",&n,&m,&a,&b)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%lld",f+i);
        scanf("%lld",&g);
        for(int i=1;i<m;i++)
        {
            long long x;
            scanf("%lld",&x);
            if(g>0)
            {
                long long d=gcd(g,x);
                double ff=1.0*g*x/d;
                if(ff>=inf)g=-1;
                else g=g/d*x;
            }
        }
        printf("%lld\n",cal(b)-cal(a-1));
    }
    return 0;
}