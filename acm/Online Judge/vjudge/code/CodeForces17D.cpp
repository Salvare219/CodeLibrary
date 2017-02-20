#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long phi(long long s)
{
	int ret=1;
	for(int i=2;i*i<=s;i++)
		if(s%i==0)
		{
			s/=i,ret*=i-1;
			while(s%i==0) s/=i,ret*=i;
		}
    if(s>1) ret*=s-1;
    return ret;
}
long long pow_mod(long long a,long long b,long long mod)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=(c*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return c;
}
char a[1000005],b[1000005],te[100];
bool cmp(long long mod)
{
    int len=0,t=mod;
    while(t)len++,t/=10;t=mod;
    for(int i=len-1;i>-1;i--)
        te[i]=t%10+'0',t/=10;
    t=strlen(b);
    if(t>len)return 1;
    else if(t<len)return 0;
    else
    {
        int i;
        for(i=0;i<len;i++)
            if(b[i]!=te[i])break;
        if(i==len)return 0;
        if(b[i]<=te[i])return 0;
        else return 1;
    }
}
int main()
{
 //   freopen("1.txt","r",stdin);
    long long aa=0,bb=0,c,mod;
    scanf("%s%s%I64d",a,b,&c);
    for(int i=0;a[i];i++)
        aa=(aa*10+a[i]-'0')%c;
    mod=phi(c);
    long long x=(aa-1+c)%c,ans;
    if(cmp(mod)) //mod<n return 1
    {
        for(int i=0;b[i];i++)
            bb=(bb*10+b[i]-'0')%mod;
        bb=(bb-1+mod)%mod;
        bb+=mod;
        ans=(pow_mod(aa,bb,c)*x)%c;
        if(ans==0)ans=c;
        printf("%I64d\n",ans);
    }
    else
    {
        for(int i=0;b[i];i++)
            bb=bb*10+b[i]-'0';
        bb=(bb-1+c)%c;
        ans=(pow_mod(aa,bb,c)*x)%c;
        if(ans==0)ans=c;
        printf("%I64d\n",ans);
    }
    return 0;
}
