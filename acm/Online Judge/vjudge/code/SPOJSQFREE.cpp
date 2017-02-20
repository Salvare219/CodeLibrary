#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 10000100;

bool p[maxn];

int mu[maxn],prime[maxn],cnt;


//线性筛选求莫比乌斯反演
void Init()
{
    memset(p,0,sizeof(p));
    mu[1] = 1;
    cnt = 0;
    for(int i=2; i<maxn; i++){
        if(!p[i]){
            prime[cnt++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<cnt&&i*prime[j]<maxn; j++){
            p[i*prime[j]] = 1;
            if(i%prime[j]) mu[i*prime[j]] = mu[prime[j]]*mu[i];
            else
                break;
        }
    }
}

int main()
{
    Init();
    LL n,ans;
    int ca;
    scanf("%d",&ca);
    while(ca--){
        scanf("%lld",&n);
        ans=0;
        for(int i=1;i<=n/i;i++){
            if(mu[i])
                ans+=n/i/i*mu[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
