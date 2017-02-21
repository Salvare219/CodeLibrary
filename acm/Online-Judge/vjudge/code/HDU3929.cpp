#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long ff=(1ll<<60)-1;
long long a[55];
int n;
inline long long dfs(long long s,int t)
{
    long long ans=0;
    for(int i=t+1;i<n;i++)
        ans-=2*dfs(s&a[i],i);
    ans*=1ll<<__builtin_popcount(s);
    return ans;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%I64d",a+i);
        int lim=1<<n;
        long long ans=0;
        //for(int i=0;i<n;i++)
        //    ans+=dfs(ff&a[i],i);
        for(int i=1;i<lim;i++)
        {
            int cnt=0;
            long long st=ff;
            for(int j=i;j;j^=j&-j)
            {
                cnt++;
                st&=a[__builtin_ctz(j&-j)];
            }
            if(cnt&1)ans+=(1ll<<__builtin_popcountll(st))*(1ll<<(cnt-1));
            else ans-=(1ll<<__builtin_popcountll(st))*(1ll<<(cnt-1));
        }
        printf("Case #%d: %I64d\n",ti++,ans);
    }
    return 0;
}