#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//    freopen("1.txt","r",stdin);
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",ti++);
        long long c,c1,c2,v1,v2;
        scanf("%lld%lld%lld%lld%lld",&c,&c1,&v1,&c2,&v2);
        if(c1>c2) swap(c1,c2),swap(v1,v2);
        if(c2>50000)
        {
            long long ans=0;
            for(int i=0;i*c2<=c;i++)
                ans=max(ans,(c-i*c2)/c1*v1+i*v2);
            printf("%lld\n",ans);
        }
        else
        {
            if(v1*c2>v2*c1) swap(v1,v2),swap(c1,c2);
            long long ans=0;
            for(int i=0;i<=c2 && c-i*c1>=0;i++)
                ans=max(ans,(c-i*c1)/c2*v2+i*v1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}