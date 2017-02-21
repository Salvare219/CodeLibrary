#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int num[155];
int sg[2000];
int k,n;
int dfs(int x)
{
    if(sg[x]!=-1) return sg[x];
    bool vis[2050]={0};
    for(int i=0;i<k;i++)
        for(int j=num[i];j<=x;j++)
            vis[dfs(j-num[i])^dfs(x-j)]=1;
    for(int j=0;;j++)
        if(vis[j]==0) return sg[x]=j;
}
int main()
{
    sg[0]=0;
    while(scanf("%d",&k)==1)
    {
        for(int i=0;i<k;i++)
            scanf("%d",num+i);
        sort(num,num+k);
        int s=1;
        for(int i=1;i<k;i++)
            if(num[i]!=num[s-1]) num[s++]=num[i];
        k=s;
        scanf("%d",&n);
        memset(sg,-1,sizeof(sg));
        for(int i=0;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            if(dfs(m)) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
