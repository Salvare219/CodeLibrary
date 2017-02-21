#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long n;
int prim[66],pk;
long long cc(long long a,int b)
{
    long long c=1;
    for(int i=0;i<b;i++)
        c*=a;
    return c;
}
int main()
{
    //freopen("1.txt", "r", stdin);
    for(int i=2;i<70;i++)
    {
        int f=1;
        for(int j=2;j<i;j++)
            if(i%j==0)f=0;
        if(f)prim[pk++]=i;
    }
    while(~scanf("%I64d",&n))
    {
        long long ans=1;
        for(int i=0;i<pk;i++)
            if(prim[i]<60)
            {
                long long c=pow(n,1.0/prim[i]);
                while(pow(1.0*c,prim[i])<=n)c++;
                if(c==2)break;
                ans+=c-2;
            }
        for(int i=0;i<pk;i++)
            for(int j=i+1;j<pk;j++)
                if(prim[i]*prim[j]<60)
                {
                    long long c=pow(n,1.0/prim[i]/prim[j]);
                    while(pow(1.0*c,prim[i]*prim[j])<=n)c++;
                    if(c==2)break;
                    ans-=c-2;
                }
        if(n>=cc(2,30))ans++;
        if(n>=cc(2,42))ans++;
        if(n>=cc(3,30))ans++;
        printf("%I64d\n",ans);
    }
    return 0;
}
