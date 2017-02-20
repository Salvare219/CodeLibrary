#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> gra[1000005],g2[1000005];
bool inq[1000005];
int now[1000005];
int n,m;
void spfa(int s)
{
    int x,w,to,m1,m2;
    queue<int> q;
    for(int i=1;i<=n;i++) inq[i]=0,now[i]=-1;
    q.push(s);now[s]=0;
    while(!q.empty())
    {
        m1=1e7;m2=0;
        x=q.front();q.pop();inq[x]=0;
        for(int i=0;i<g2[x].size();i++)
            if(now[g2[x][i]]<0) m2=1e7;
            else m1=min(m1,now[g2[x][i]]),m2=max(m2,now[g2[x][i]]);
        if(x!=s)now[x]=min(m2,m1+1);
        for(int i=0;i<gra[x].size();i++)
        {
            to=gra[x][i];
            if(now[to]<0)
            {
                now[to]=now[x]+1;
                inq[to]=1;q.push(to);
            }
            else
            {
                if(now[x]+1<now[to])
                {
                    now[to]=now[x]+1;
                    if(inq[to]==0)inq[to]=1,q.push(to);
                }
            }
        }
    }
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&x,&y),gra[y].push_back(x),g2[x].push_back(y);
    scanf("%d%d",&x,&y);spfa(y);
    printf("%d\n",now[x]);
}
