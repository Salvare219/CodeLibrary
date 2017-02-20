#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int a[55];
long long gcd(long long a,long long b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        int mm=200;
        int k=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+k);
            if(a[k])k++;
        }
        n=k;
        long long ans=0;m--;
        for(int i=0;i<(1<<n);i++)
        {
            int cnt=0;
            long long te=1;
            for(int j=0;j<n;j++)
                if((1<<j)&i)
                {
                    cnt++;
                    te=te*a[j]/gcd(te,a[j]);
                }
            if(cnt&1)ans-=m/te;
            else ans+=m/te;
        }
        printf("%I64d\n",m-ans);
    }
    return 0;
}
