#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int m[200050];
int main()
{
    int n,q,t;
    while(~scanf("%d%d",&n,&q))
    {
        long long sum=0,c;
        memset(m,0,sizeof(m));
        for(int i=0;i<n;i++)
            scanf("%d",&t),sum+=t,m[t]++;
        int x,y;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d%lld",&x,&y,&c);
            for(int i=y;i>=x;i--)
                sum+=m[i]*c;
            for(int i=y;i>=x;i--)
                m[i+c]+=m[i],m[i]=0;
        }
        printf("%lld\n",sum);
    }
    return 0;
}