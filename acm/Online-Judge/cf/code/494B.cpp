#include <bits/stdc++.h>
using namespace std;


const int mod=1000000007;
char s[200050];
char t[200050];
int fail[200050];
bool ed[200050];
long long dp[200050];
long long s1[200050];
long long s2[200050];
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%s%s",s,t);
    int i=0,j=-1;
    fail[0]=-1;
    while(t[i])
    {
        while(j!=-1 && t[i]!=t[j]) j=fail[j];
        i++;j++;
        fail[i]=j;
    }
    i=0;j=0;
    while(s[i])
    {
        while(j!=-1 && s[i]!=t[j] ) j=fail[j];
        i++;j++;
        if(t[j]==0)
        {
            ed[i-1]=1;
        }
    }
    int n=strlen(s),f=strlen(t);
    for(int i=1;i<=n;i++)
    {
        if(ed[i-1])
        {
            dp[i]=(dp[i]+s2[i-f]+i-f+1)%mod;
        }
        else
        {
            dp[i]=dp[i-1];
        }
        s1[i]=(s1[i-1]+dp[i])%mod;
        s2[i]=(s2[i-1]+s1[i])%mod;
    }
    printf("%I64d\n",s1[n]%mod);
    return 0;
}
