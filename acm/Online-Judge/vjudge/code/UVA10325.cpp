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
int n,m;
const long long inf=1ll<<31;
long long cal(long long c)
{
    long long ans=0;
    for(int i=1;i<(1<<n);i++)
    {
        long long sum=0;
        int cnt=0;
        for(int j=0;j<n;j++)
            if((1<<j)&i)
            {
                if(sum==0)sum=f[j];
                else
                {
                    long long d=gcd(sum,f[j]);
                    double ff=1.0*sum*f[j]/d;
                    if(ff>=inf)
                    {
                        sum=-1;
                        break;
                    }
                    else sum=sum/d*f[j];
                }
                cnt++;
            }
        if(sum!=-1)
        {
            long long how=c/sum;
            if(cnt&1)ans+=how;
            else ans-=how;
        }
    }
    return ans;
}
int main()
{
    //freopen("1.txt","r",stdin);
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<n;i++)
            scanf("%lld",f+i);
        printf("%lld\n",m-cal(m));
    }
    return 0;
}
