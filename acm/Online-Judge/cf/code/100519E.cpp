#include<bits/stdc++.h>
using namespace std;

long long s1,n;
int s2,d;

inline void check(long long k)
{
    if(k==1)
        return;
    long long m=n;
    int s=0;
    while(m%k==d)
        s++,m/=k;
    if(s>s2||(s==s2&&k<s1))
        s1=k,s2=s;
}

int main()
{
    //freopen("1.txt","r",stdin);
    long long m;
    int i;
    scanf("%I64d%d",&n,&d);
    m=n-d;
    s1=2;s2=0;
    if(m>0)
    {
        for(i=1;1ll*i*i<m;i++)
            if(m%i==0)
                check(i),check(m/i);
        if(1ll*i*i==m)
            check(i);
    }
    else if(m==0)
        s1=max(n+1,2ll),s2=1;
    printf("%I64d %d\n",s1,s2);
    return 0;
}
