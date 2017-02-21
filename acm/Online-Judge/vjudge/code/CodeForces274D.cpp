#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

pair<int,int>a[100050];
vector<int>gra[200050];
int n,m,k;
int in[200050],ans[100050];
bool vis[200050];
void dfs(int s)
{
    if(s<m)ans[k++]=s+1;vis[s]=1;
    for(int i=0;i<gra[s].size();i++)
    {
        in[gra[s][i]]--;
        if(in[gra[s][i]]==0)dfs(gra[s][i]);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int x,ex=m;k=0;
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=0;j<m;j++)
                scanf("%d",&x),a[j]=make_pair(x,j);
            sort(a,a+m);j=0;
            while(a[j].first==-1)j++;
            for(;j<m;j++)
            {
                while(j+1<m&&a[j].first==a[j+1].first)
                {
                    gra[a[j].second].push_back(ex+1);in[ex+1]++;
                    gra[ex].push_back(a[j].second);in[a[j].second]++;
                    j++;
                }
                gra[a[j].second].push_back(ex+1);in[ex+1]++;
                gra[ex++].push_back(a[j].second);in[a[j].second]++;
            }
            ex++;
        }
        bool f=0;
        for(int i=0;i<ex;i++)
            if(in[i]==0&&vis[i]==0)dfs(i);
        for(int i=0;i<m;i++)
            if(in[i])f=1;
        if(f)puts("-1");
        else
        {
            for(int i=0;i<m;i++)
                if(i)printf(" %d",ans[i]);
                else printf("%d",ans[0]);
            putchar(10);
        }
    }
    return 0;
}
