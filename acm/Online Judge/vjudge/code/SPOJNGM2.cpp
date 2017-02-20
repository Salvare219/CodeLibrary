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
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%d",a+i);
    long long ans=n;
    for(int i=1;i<(1<<k);i++)
    {
        int cnt=0;
        long long sum=0;
        for(int j=i;j;j&=j-1)
        {
            int h=__builtin_ctz(j&-j);
            if(sum==0)sum=a[h];
            else sum=sum/gcd(sum,a[h])*a[h];
            cnt++;
        }
        if(cnt&1)ans-=n/sum;
        else ans+=n/sum;
    }
    printf("%d\n",(int)ans);
    return 0;
}
