#include <bits/stdc++.h>
using namespace std;


vector<int>gra[100050];
vector<int>lw[100050];
vector<int>id[100050];
long long how[100050];
long long lca[100050];
long long sl[100050];
long long dep[100050];
long long wic[100050];
long long sd[100050];
long long ld[100050];
int n,m;
void dfs(int s,int p)
{
    int y;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            dep[y]=dep[s]+lw[s][i];
            wic[id[s][i]]=y;
            dfs(y,s);
            sl[s]+=sl[y];
            sd[s]+=sd[y];
            how[s]+=how[y];
            ld[s]+=ld[y];
        }
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            lca[s]+=(how[s]-how[y])*(how[y]);
        }
    lca[s]/=2;
    lca[s]+=how[s];
    how[s]++;
    sl[s]+=lca[s];
    sd[s]+=dep[s];
    ld[s]+=lca[s]*dep[s];
}
int cw[100050];
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);
    int x,y,w;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        gra[x].push_back(y);
        gra[y].push_back(x);
        lw[x].push_back(w);
        lw[y].push_back(w);
        id[x].push_back(i);
        id[y].push_back(i);
        cw[i]=w;
    }
    dep[1]=0;
    dfs(1,0);
    scanf("%d",&m);
    long long sumd=sd[1];
    long long suml=ld[1];
    long long cn2=6ll*(n-1);
    long long cn3=1ll*n*(n-1);
    for(int i=0;i<m;i++)
    {
        int r,w;
        scanf("%d%d",&r,&w);
        int pos=wic[r];
        long long dw=cw[r]-w;
        cw[r]=w;

        sumd-=how[pos]*dw;
        suml-=sl[pos]*dw;

        long long d1=cn2*sumd;
        long long d2=12ll*suml;
        printf("%.10f\n",1.0*(d1-d2)/cn3);
    }
    return 0;
}
