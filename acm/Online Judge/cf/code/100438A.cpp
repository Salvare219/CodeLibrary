#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

vector<int>gra[600];
int d[600];
int p[600];
bool v[600];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            x++;y++;
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        int fin=100000;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                v[j]=0,d[j]=10000;
            queue<int>q;
            v[i]=1;d[i]=0;
            q.push(i);
            int ans=10000;
            while(!q.empty())
            {
                x=q.front();q.pop();
                for(int i=0;i<gra[x].size();i++)
                {
                    y=gra[x][i];
                    if(d[y]>d[x]+1)
                    {
                        ans=min(d[x]+d[y]+1,ans);
                        d[y]=d[x]+1;
                        p[y]=x;
                        if(v[y]==0)
                        {
                            v[y]=1;
                            q.push(y);
                        }
                    }
                }
                for(int i=0;i<gra[x].size();i++)
                    if(p[y=gra[x][i]]!=x&&p[x]!=y)
                        ans=min(ans,d[x]+d[y]+1);
            }
            fin=min(ans,fin);
        }
        printf("Case %d: ",ti++);
        if(fin>1000)printf("impossible\n");
        else printf("%d\n",fin);
    }
    return 0;
}
