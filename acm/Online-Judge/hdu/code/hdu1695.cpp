#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int prime[100050],mu[100050];
int pk;
bool vis[100050];
void cal()
{
    mu[1]=1;
    for(int i=2;i<100005;i++)
    {
        if(!vis[i]) prime[pk++]=i,mu[i]=-1;
        for(int j=0;j<pk && i*prime[j]<100005;j++)
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
    int t,ti=1;scanf("%d",&t);
    cal();
    while(t--)
    {
        int a,b,k;
        scanf("%*d%d%*d%d%d",&a,&b,&k);
        if(k==0)printf("Case %d: 0\n",ti++);
        else
        {
            if(a>b)swap(a,b);
            long long sum=0,sum2=0;
            for(int i=k;i<=a;i+=k)
                sum+=1ll*mu[i/k]*(a/i)*(b/i),sum2+=1ll*mu[i/k]*(a/i)*(a/i);
            printf("Case %d: %I64d\n",ti++,sum-sum2/2);
        }
    }
    return 0;
}
