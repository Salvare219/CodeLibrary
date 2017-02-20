#include<bits/stdc++.h>
using namespace std;

char s[1000005];
const int mod=1000000007;
long long dp1[1000005],dp2[1000005],sum[1000005];
bool ok[1000005];
int main()
{
    int n,k,f=0;scanf("%d%d%s",&n,&k,s+1);
    dp1[0]=1;s[0]='W';
    for(int i=1;s[i];i++)
    {
        if(s[i]=='W')f=i;
        dp1[i]=(s[i]=='X'?2*dp1[i-1]:dp1[i-1])%mod;
        if(f<=i-k&&s[i-k]!='B')dp1[i]=(dp1[i]-(i-k==0?1:dp1[i-k-1]))%mod,ok[i]=1;
    }
    for(int i=n/2;i>0;i--)swap(s[i],s[n-i+1]);
    dp2[0]=sum[0]=1;f=0;s[0]='B';
    for(int i=1;s[i];i++)
    {
        if(s[i]=='B')f=i;
        dp2[i]=(s[i]=='X'?2*dp2[i-1]:dp2[i-1])%mod;
        sum[i]=(s[i]=='X'?2*sum[i-1]:sum[i-1])%mod;
        if(f<=i-k&&s[i-k]!='W')dp2[i]=(dp2[i]-(i-k-1==-1?1:dp2[i-k-1]))%mod;
    }
    long long ans=0;
    for(int i=k;i<=n-k;i++)
        if(ok[i])ans=(ans+(i-k==0?1:dp1[i-k-1])*(sum[n-i]-dp2[n-i]))%mod;
    printf("%I64d\n",(ans+mod)%mod);
    return 0;
}
