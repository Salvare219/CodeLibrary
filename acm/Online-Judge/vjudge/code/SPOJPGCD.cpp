#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int prim[10000005],mu[10000005];
int cnt[10000005];
int pk;
bool vis[10000005];
void cal()
{
    mu[1]=1;
    for(int i=2;i<10000001;i++)
    {
        if(!vis[i]) prim[pk++]=i,mu[i]=-1;
        for(int j=0;j<pk && i*prim[j]<10000001;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j])
            {
                mu[i*prim[j]]=-mu[i];
            }
            else
            {
                mu[i*prim[j]]=0;
                break;
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t;cal();
    scanf("%d",&t);
    for(int i=1;i<10000001;i++)
        if(mu[i])
            for(int j=0;j<pk&&i*prim[j]<10000001;j++)
                cnt[i*prim[j]]+=mu[i];
    for(int i=2;i<10000001;i++)
        cnt[i]+=cnt[i-1];
    //for(int i=1;i<10000001;i++)mu[i]=-mu[i]*mi[i];
    //for(int i=1;i<10000001;i++)mu[i]+=mu[i-1];
    while(t--)
    {
        int a,b,k;scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        long long ans=0;
        for(int i=1;i<=a;i=k+1)
        {
            k=min(a/(a/i),b/(b/i));
            ans+=1ll*(cnt[k]-cnt[i-1])*(a/i)*(b/i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
