#include<bits/stdc++.h>
using namespace std;


vector<int>gra[5050];
int v[20];
int col[5050];
int n,m,k;
void dfs(int s)
{
    int y;
    for(int i=0;i<gra[s].size();i++)
        if(col[y=gra[s][i]])
        {
            v[col[y]]|=1;
            v[col[y]%k+1]|=2;
        }
    for(int i=1;i<=k;i++)
        if(v[i]==2)
        {
            col[s]=i;
            break;
        }
    for(int i=1;i<=k;i++)
        v[i]=0;
    for(int i=0;i<gra[s].size();i++)
        if(col[y=gra[s][i]]==0)
        {
            dfs(y);
        }
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("galaxy.in", "r", stdin);
    freopen("galaxy.out", "w", stdout);
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    for(int i=1;i<=k;i++)
        col[i]=i;
    for(int i=1;i<=k;i++)
        for(int j=0;j<gra[i].size();j++)
            if(col[gra[i][j]]==0)
                dfs(gra[i][j]);
    for(int i=1;i<=n;i++)
        printf("%d ",col[i]);
    return 0;
}
