#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int n,m;
int fac[100],k;
long long pow_mod(long long a)
{
    int b=n;
    long long c=1;
    while(b)
    {
        if(b&1)c*=a;
        b>>=1;
        a*=a;
    }
    return c;
}
long long dfs(long long s,int t)
{
    long long ans=pow_mod(m/s);
    for(int i=t;i<k;i++)
        ans-=dfs(s*fac[i],i+1);
    return ans;
}
int main()
{
    //freopen("1.txt", "r", stdin);
    while(~scanf("%d%d",&n,&m))
    {
        if(m==1)puts("1");
        else
        {
            k=0;
            int f=m;
            for(int i=2;i*i<=f;i++)
                if(f%i==0)
                {
                    fac[k++]=i;
                    do f/=i;
                    while(f%i==0);
                }
            if(f!=1)fac[k++]=f;
            printf("%I64d\n",dfs(1,0));
        }
    }
    return 0;
}
