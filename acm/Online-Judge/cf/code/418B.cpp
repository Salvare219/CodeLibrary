#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int x,k,m;
    int st;
    bool operator<(const struct p&a)const{return k>a.k;}
}f[200];
long long dp[(1<<20)+5];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,b;scanf("%d%d%d",&n,&m,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&f[i].x,&f[i].k,&f[i].m);
        int sa=0,x;
        for(int j=0;j<f[i].m;j++)
            scanf("%d",&x),sa|=1<<(x-1);
        f[i].st=sa;
    }
    sort(f,f+n);
    long long inf=1<<30;
    inf*=inf;
    int lim=1<<m;
    for(int i=0;i<lim;i++)dp[i]=inf;
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        int sa=f[i].st;
        for(int j=0;j<lim;j++)
        {
            if(j==0)dp[j|sa]=min(dp[j|sa],dp[0]+f[i].x+1ll*f[i].k*b);
            else dp[j|sa]=min(dp[j|sa],dp[j]+f[i].x);
        }
    }
    if(dp[lim-1]<inf)printf("%I64d\n",dp[lim-1]);
    else puts("-1");
    return 0;
}
