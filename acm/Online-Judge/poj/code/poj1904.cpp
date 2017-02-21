#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>gra[5005];
int n;
bool v[5005];
int stack[5005],sk;
int low[5005],scc[5005];
int timer,cnt;
void tarjan(int s)
{
    v[s]=1;
    int to,temp=low[s]=++timer;
    stack[sk++]=s;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(v[to]==0)tarjan(to);
        low[s]=min(low[to],low[s]);
    }
    if(temp==low[s])
    {
        do
        {
            to=stack[--sk];
            low[to]=0x3fffffff;
            scc[to]=cnt;
        }while(stack[sk]!=s);
        cnt++;
    }
}
inline void out(int c)
{
    if(c>9)out(c/10);
    putchar(c-c/10*10+'0');
}
int main()
{
    while(~scanf("%d",&n))
    {
        int x,y;
        for(int i=1;i<=2*n;i++)
            gra[i].clear(),v[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<x;j++)
                scanf("%d",&y),gra[i].push_back(y+n);
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&y),gra[y+n].push_back(i);
        cnt=1;timer=0;
        for(int i=1;i<=n;i++)
            if(v[i]==0)
                tarjan(i);
        for(int i=1;i<=n;i++)
        {
            x=scc[i];
            int tot=0;
            for(int j=0;j<gra[i].size();j++)
                if(scc[y=gra[i][j]]==x)low[tot++]=y-n;
            out(tot);putchar(' ');sort(low,low+tot);
            for(int j=0;j<tot;
            j++)
                out(low[j]),putchar(' ');
            putchar(10);
        }
    }
    return 0;
}
