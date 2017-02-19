#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int a[20000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        scanf("%d",a+i);
    }
    int fuck;scanf("%d",&fuck);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int fa=a[i]^fuck;
        if(__builtin_popcount(fa)<=k)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
