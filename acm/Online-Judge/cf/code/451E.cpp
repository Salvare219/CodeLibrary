#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


const int mod=1000000007;
long long a[55];
long long pow_mod(long long a,long long b)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=c*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
long long inv[55];
long long C(long long n,long long m)
{
    if(n<m)return 0;
    long long f=1;n%=mod;
    for(int i=0;i<m;i++)
        f=f*(n-i)%mod;
    return f*inv[m]%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    inv[1]=inv[0]=1;
    for(int i=2;i<30;i++)
        inv[i]=inv[i-1]*pow_mod(i,mod-2)%mod;
    long long n,s,ans=0;scanf("%I64d%I64d",&n,&s);
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i);
    for(int i=0;i<(1<<n);i++)
    {
        long long t=s,cnt=0;
        for(int j=0;j<n;j++)
            if((1<<j)&i)
            {
                cnt++;
                t-=a[j]+1;
            }
        if(cnt&1)ans=(ans-C(t+n-1,n-1))%mod;
        else ans=(ans+C(t+n-1,n-1))%mod;
    }
    printf("%I64d\n",(ans+mod)%mod);
    return 0;
}
