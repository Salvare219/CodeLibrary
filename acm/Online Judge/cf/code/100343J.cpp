#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int n,m;
vector<pair<int,int> > gra[1000005];
bool vis[1000005];
int stack[1000005],sk;
int stack2[1000005],sk2;
vector<int>sz[1000005];
vector<int>lin[1000005];
int scc[1000005];
int las[1000005];
int cnt;
int find(int s)
{
    return scc[s]==s?s:scc[s]=find(scc[s]);
}
void tarjan(int s)
{
    vis[s]=1;
    int to;
    stack[sk++]=s;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i].first;
        stack2[sk2++]=gra[s][i].second;
        if(vis[to]==0)tarjan(to);
        else
        {
            int fa,la;
            do
            {
                la=stack2[--sk2];
                fa=stack[--sk];
                sz[cnt].push_back(fa);
                lin[cnt].push_back(la);
            }while(find(stack[sk])!=find(scc[to]));

            scc[cnt]=cnt;
            for(int j=0;j<sz[cnt].size();j++)
                scc[sz[cnt][j]]=scc[cnt];

            stack[sk++]=cnt++;
        }
    }
}
void cal(int s)
{
    if(s<=n)
        printf("vertex %d\n",s);
    else
    {
        printf("wheel %d\n",(int)sz[s].size());
        for(int i=sz[s].size()-1;i>-1;i--)
        {
            cal(sz[s][i]);
            printf("edge %d\n",lin[s][i]);
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("wheels.in","r",stdin);
    freopen("wheels.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        gra[x].push_back(make_pair(y,i+1));
    }
    cnt=n+1;
    for(int i=1;i<=n;i++)
        sz[i].push_back(i),scc[i]=i;
    tarjan(1);/*
    for(int i=1;i<cnt;i++)
    {
        for(int j=0;j<sz[i].size();j++)
            printf("%d ",sz[i][j]);
        printf("\n");
    }*/
    cal(cnt-1);
    return 0;
}
