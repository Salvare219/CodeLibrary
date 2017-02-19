#include <bits/stdc++.h>
using namespace std;


const int mod=1000000007;
long long fac[100050];
long long inv[100050];
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
long long C(int n,int m)
{
    if(m>n)return 0;
    if(m<0)return 0;
    if(n<0)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
char s[100050];
long long sum[100050];
long long sum2[100050];
int n,k;
long long len(int l)
{
    return ((n-l-1)*sum[n-l]%mod-sum2[n-l-1])%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%s",&n,&k,s+1);
    fac[0]=inv[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=pow_mod(fac[i],mod-2);
    }
    for(int i=1;i<=n;i++)
        sum[i]=(sum[i-1]+s[i]-'0')%mod;
    for(int i=1;i<=n;i++)
        sum2[i]=(sum2[i-1]+sum[i])%mod;
    long long ans=0,g=0,las=0;
    for(int l=1;l<=n-2;l++)
    {
        if(l==1)g=(sum[n-1]-sum[1])%mod;
        else g=((g-las)*10+sum[n-1]-sum[l])%mod;
        ans=(ans+g*C(n-l-2,k-2))%mod;
        las=(las+(s[n-l]-'0')*pow_mod(10,l-1))%mod;
    }
    long long s1=0,s2=0;
    for(int l=1;l<n;l++)
    {
        s1=(s1*10+s[l]-'0')%mod;
        s2=(s2+(s[n-l+1]-'0')*pow_mod(10,l-1))%mod;
        ans=(ans+s1*C(n-l-1,k-1))%mod;
        ans=(ans+s2*C(n-l-1,k-1))%mod;
    }
    s1=(s1*10+s[n]-'0')%mod;
    if(k==0)ans=(ans+s1)%mod;
    ans%=mod;
    ans+=mod;
    ans%=mod;
    printf("%d\n",(int)ans);
    return 0;
}
