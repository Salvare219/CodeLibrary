#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> gra[10050],q[10050];
int ans;
int com[10050];
bool vis[10050];
inline int find(int s)
{return s==com[s]?s:com[s]=find(com[s]);}
void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<q[s].size();i++)
        if(vis[q[s][i]]) ans=find(q[s][i]);
    int z;
    for(int i=0;i<gra[s].size();i++)
        z=gra[s][i],dfs(z),com[z]=s;
}
int main()
{
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        int n,root;scanf("%d",&n);
        for(int i=1;i<=n;i++) q[i].clear(),gra[i].clear(),com[i]=i,vis[i]=1;
        for(int i=1;i<n;i++)
            scanf("%d%d",&x,&y),gra[x].push_back(y),vis[y]=0;
        for(int i=1;i<=n;i++)
            if(vis[i]) vis[i]=0,root=i;
        scanf("%d%d",&x,&y);
        q[x].push_back(y);q[y].push_back(x);
        dfs(root);
        printf("%d\n",ans);
    }
    return 0;
}