#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[5000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    int ans=0,x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        ans+=min(a[x],a[y]);
    }
    printf("%d\n",ans);
    return 0;
}
