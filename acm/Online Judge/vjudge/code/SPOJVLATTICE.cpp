#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 1000005;
inline long long sqr(long long x) {return x*x;}
inline long long cube(long long x) {return x*x*x;}
int prime[MAXN],mu[MAXN];
int pk,n;
bool com[MAXN],vis[MAXN];
void cal()
{
    mu[1]=1;
    for(int i=2;i<MAXN;i++)
    {
        if(!vis[i]) prime[pk++]=i,mu[i]=-1;
        for(int j=0;j<pk && i*prime[j]<MAXN;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]) mu[i*prime[j]]=-mu[i];
            else
            {
                mu[i*prime[j]]=0;
                break;
            }
        }
    }
}
int main()
{
    int t;scanf("%d",&t);
    cal();
    while(t--)
    {
        scanf("%d",&n);
        long long ans=3;
        for(int i=1;i<= n;i++)
            ans+=mu[i]*cube(n/i);
        for(int i=1;i<= n;i++)
            ans+=mu[i]*sqr(n/i)*3;
        printf("%lld\n",ans);
    }
    return 0;
}
