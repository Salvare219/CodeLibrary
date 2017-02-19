#include<bits/stdc++.h>
using namespace std;


vector<int>c[100050];
int com[100050];
vector<int>g[100050];
vector<int>gra[100050];
int deg[100050];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        com[i]=i;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        c[x].push_back(y);
        com[find(x)]=find(y);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        g[find(i)].push_back(i);
    int ans=n;
    for(int i=1;i<=n;i++)
        if(g[i].size()!=0)
        {
            int cnt=0;
            for(int j=0;j<g[i].size();j++)
                gra[g[i][j]].clear(),cnt++;
            for(int j=0;j<g[i].size();j++)
            {
                int x=g[i][j];
                for(int z=0;z<c[x].size();z++)
                    gra[x].push_back(c[x][z]),deg[c[x][z]]++;
            }
            queue<int>q;
            for(int j=0;j<g[i].size();j++)
                if(deg[g[i][j]]==0)
                    q.push(g[i][j]);
            while(!q.empty())
            {
                cnt--;
                int x=q.front();q.pop();
                for(int j=0;j<gra[x].size();j++)
                {
                    int y=gra[x][j];
                    deg[y]--;
                    if(deg[y]==0)
                        q.push(y);
                }
            }
            if(cnt==0)ans--;
        }
    printf("%d\n",ans);
    return 0;
}
