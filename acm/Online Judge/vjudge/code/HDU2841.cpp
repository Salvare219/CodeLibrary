#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int prim[100050],k;
bool v[100050];
int a,b,c;
long long dfs(long long s,int t)
{
    long long ca=a/s,cb=b/s;
    long long ans=1ll*ca*cb;
    for(int i=t;i<k;i++)
        if(s*prim[i]<=a)ans-=dfs(s*prim[i],i+1);
        else break;
    return ans;
}
int main()
{
    //freopen("1.txt", "r", stdin);
    for(int i=2;i<100005;i++)
    {
        if(v[i]==0)prim[k++]=i;
        for(int j=0;j<k&&prim[j]*i<100005;j++)
        {
            v[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        printf("%I64d\n",dfs(1,0));
    }
    return 0;
}
