#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
using namespace std;


int gra[65][2],n;
bool vis[100005];
int p[100005],o[65];
bool find(int s)
{
    for(int i=gra[s][0];i<=gra[s][1];i++)
        if(vis[i]==0)
        {
            vis[i]=1;
            if(p[i]==0 || find(p[i]))
            {
                p[i]=s;
                return 1;
            }
        }
    return 0;
}
int max_match()
{
    int ans=0;
    memset(p,0,sizeof(p));
    for(int i=n;i>0;i--)
    {
        memset(vis,0,sizeof(vis));
        if(find(i)) o[ans++]=i;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&gra[i][0],&gra[i][1]);
        int temp;
        printf("%d\n",temp=max_match());
        for(int i=temp-1;i>0;i--)
            printf("%d ",o[i]);
        printf("%d\n",o[0]);
    }
    return 0;
}