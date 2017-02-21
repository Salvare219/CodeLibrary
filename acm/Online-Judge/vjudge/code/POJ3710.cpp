#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



vector<int> gra[105];
int dfn[105];
bool vis[105];
int sg(int now,int fa,int deep)
{
    int sum=0;
    bool flag=1;
    dfn[now]=deep;
    for(int i=0;i<gra[now].size();i++)
    {
        if(vis[gra[now][i]]==0)
        {
            if(gra[now][i]==fa && flag)
            {
                flag=0;
                continue;
            }
            if(dfn[gra[now][i]])
            {
                vis[now]=1;
                if((deep-dfn[gra[now][i]])%2) return dfn[gra[now][i]]-deep;
                return dfn[gra[now][i]]-deep+1;
            }
            else sum^=sg(gra[now][i],now,deep+1)+1;
        }
    }
    return sum;
}
int main()
{
    int c;
    while(scanf("%d",&c)==1)
    {
        int n,m,x,y,sum=0;
        for(int k=0;k<c;k++)
        {
            scanf("%d%d",&n,&m);
            for(int i=n;i>0;i--)
            {
                vis[i]=0;
                dfn[i]=0;
                gra[i].clear();
            }
            for(int i=0;i<m;i++)
            {
                scanf("%d%d",&x,&y);
                gra[x].push_back(y);
                gra[y].push_back(x);
            }
            sum^=sg(1,0,1);
        }
        if(sum) printf("Sally\n");
        else printf("Harry\n");
    }
    return 0;
}





