//#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;


char s[1000050];
int cal()
{
    int l=strlen(s),k=0;
    for(int i=0;i<l;i++)
        if(s[i]=='(')k++;
        else
        {
            if(k)k--;
            else return -1;
        }
    return k;
}
const int mod=1000000007;
long long fac[1000050];
long long inv[1000050];
long long f[1000050];
long long C(int n,int m)
{
    if(n<m)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    fac[0]=inv[0]=f[0]=1;
    fac[1]=inv[1]=f[1]=1;
    for(int i=2;i<1000005;i++)
    {
        f[i]=(-mod/i)*f[mod%i]%mod;
        if(f[i]<0)f[i]+=mod;
        inv[i]=inv[i-1]*f[i]%mod;
        fac[i]=fac[i-1]*i%mod;
    }
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        int d=cal();
        int l=strlen(s);
        if(d==-1||n%2)puts("0");
        else
        {
            int r=n-l;
            if((r+d)%2)puts("0");
            else
            {
                if(r<d)puts("0");
                else
                {
                    long long ans=(C(r,(r+d)/2)-C(r,(r-d)/2-1))%mod;
                    ans+=mod;
                    ans%=mod;
                    printf("%I64d\n",ans);
                }
            }
        }
    }
    return 0;
}
