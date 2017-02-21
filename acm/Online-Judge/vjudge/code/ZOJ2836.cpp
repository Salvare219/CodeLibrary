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
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;
    int a[66];
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        long long ans=0;
        for(int i=1;i<(1<<n);i++)
        {
            long long sum=0;
            int cnt=0;
            for(int j=i;j;j=j&(j-1))
            {
                int h=__builtin_ctz(j);
                if(sum==0)sum=a[h];
                else sum=sum/gcd(sum,a[h])*a[h];
                cnt++;
            }
            if(cnt&1)ans+=m/sum;
            else ans-=m/sum;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
