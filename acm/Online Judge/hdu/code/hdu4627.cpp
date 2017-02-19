#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        if(n&1)printf("%I64d\n",1ll*(n/2)*(n/2+1));
        else
        {
            long long ans=n-1;
            if(n/2%2==0)ans=max(ans,1ll*(n/2-1)*(n/2+1));
            else ans=max(ans,1ll*(n/2-2)*(n/2+2));
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
