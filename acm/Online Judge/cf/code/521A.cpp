#include <bits/stdc++.h>
using namespace std;


const int mod=1000000007;
char s[100050];
int lib[300];
int pow_mod(long long a,long long b)
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
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d%s",&n,s);
    int c[6]={0};
    lib['A']=0;lib['C']=1;
    lib['G']=2;lib['T']=3;
    int k=0,cnt=0;
    for(int i=0;i<n;i++)
        c[lib[s[i]]]++,k=max(k,c[lib[s[i]]]);
    for(int i=0;i<4;i++)
        if(c[i]==k)cnt++;
    printf("%d\n",pow_mod(cnt,n));
    return 0;
}
