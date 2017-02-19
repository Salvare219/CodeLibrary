#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


vector<int> gra[30];
int dep[30],deg[30];
int vis[30],fa[30];
int dfs1(int s)
{
    vis[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(vis[gra[s][i]]==1) return 1;
        else if(vis[gra[s][i]]==0)
        {
            if(dfs1(gra[s][i]))
            {
                vis[s]=2;
                return 1;
            }
        }
    vis[s]=2;
    return 0;
}
void dfs2(int s)
{
    for(int i=0;i<gra[s].size();i++)
        if(dep[gra[s][i]]<dep[s]+1) dep[gra[s][i]]=dep[s]+1,dfs2(gra[s][i]);
}
int main()
{
    int n,m;
    char str[12];
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) gra[i].clear(),deg[i]=0;
        int ans=-1,temp,sa=-1;
        bool fl=0;
        for(int i=0;i<m;i++)
        {
            scanf("%s",str);
            gra[str[0]-'A'].push_back(str[2]-'A');
            deg[str[2]-'A']++;
            if(ans==-1 && sa==-1)
            {
                memset(vis,0,sizeof(vis));
                for(int j=0;j<n;j++)
                    if(vis[j]==0)
                    {
                        if(dfs1(j)) ans=i+1;
                    }
                if(ans==-1 && sa==-1)
                {
                    for(int j=0;j<n;j++)
                        if(deg[j]==0) temp=j;
                    memset(dep,0,sizeof(dep));
                    dfs2(temp);
                    for(int j=0;j<n;j++)
                        if(dep[j]==n-1)
                        {
                            if(sa==-1) sa=i+1;
                        }
                    if(sa!=-1)
                    {
                        for(int j=0;j<n;j++)
                            fa[dep[j]]=j;
                    }
                }
            }
        }
        if(ans!=-1) printf("Inconsistency found after %d relations.\n",ans);
        else
        {

            if(sa==-1) printf("Sorted sequence cannot be determined.\n");
            else
            {
                printf("Sorted sequence determined after %d relations: ",sa);
                for(int i=0;i<n;i++)
                    putchar(fa[i]+'A');
                printf(".\n");
            }
        }
    }
    return 0;
}
