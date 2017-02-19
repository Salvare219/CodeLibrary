#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int vis[40000];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,x,y,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        vis[x]=1;vis[y]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(vis[i]==0) ans=i;
    printf("%d\n",n-1);
    for(int i=1;i<=n;i++)
    {
        if(i==ans) continue;
        else printf("%d %d\n",ans,i);
    }
    putchar(10);
    return 0;
}
