#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


long long prim[10050],mu[10050];
int pk;
bool vis[10050];
void cal()
{
    mu[1]=1;
    for(int i=2;i<10005;i++)
    {
        if(!vis[i]) prim[pk++]=i,mu[i]=-1;
        for(int j=0;j<pk&&i*prim[j]<10005;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]) mu[i*prim[j]]=-mu[i];
            else
            {
                mu[i*prim[j]]=0;
                break;
            }
        }
    }
}
int cnt[10050];
long long C(int x)
{
    long long sum=0;
    for(int i=x;i<=10000;i+=x)
        sum+=cnt[i];
    return sum*(sum-1)*(sum-2)*(sum-3)/24;
}
int main()
{
    cal();
    int n;
    while(~scanf("%d",&n))
    {
        int x;
        for(int i=1;i<=10000;i++)cnt[i]=0;
        for(int i=0;i<n;i++)
            scanf("%d",&x),cnt[x]++;
        long long sum=0;
        for(int i=1;i<=10000;i++)
            sum+=mu[i]*C(i);
        printf("%lld\n",sum);
    }
    return 0;
}
