#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    long long m,e;
    while(scanf("%lld%lld",&m,&e)&&m)
    {
        long long wei=1ll<<e,sb=1ll<<m,ans=0;
        for(int i=0;i<m;i++)
        {
            sb/=2;
            ans+=sb*max((long long)0,(wei-m+i-1));
        }
        ans+=wei-1;
        printf("%lld\n",ans);
    }
    return 0;
}
