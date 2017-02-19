#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


vector<pair<int,int> >gra[100050];
vector<pair<int,int> >wic;
int deg[100050];
bool inq[100005];
int now[100005];
int q[100005];
int nn;
void spfa(int s)
{
    int x,w,to,front=0,tail=1;
    for(int i=1;i<=nn;i++)now[i]=0x3fffffff,inq[i]=0;
    q[0]=s;now[s]=0;
    while(front!=tail)
    {
        x=q[front++];inq[x]=0;
        if(inq[x])continue;
        if(front>nn)front=0;
        for(int i=0;i<gra[x].size();i++)
        {
            to=gra[x][i].first;
            w=gra[x][i].second;
            if(now[to]>now[x]+w)
            {
                now[to]=now[x]+w;
                if(inq[to]==0)
                {
                    inq[to]=1;
                    if(now[to]<now[q[front]])
                    {
                        if(front==0)front=nn;
                        else front--;
                        q[front]=to;
                    }
                    else
                    {
                        q[tail++]=to;
                        if(tail>nn)tail=0;
                    }
                }
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,k,x,y,w;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        gra[x].push_back(make_pair(y,w));
        gra[y].push_back(make_pair(x,w));
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        wic.push_back(make_pair(x,y));
        gra[1].push_back(make_pair(x,y));
    }
    nn=n;
    spfa(1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<gra[i].size();j++)
        {
            y=gra[i][j].first;
            w=gra[i][j].second;
            if(now[i]+w==now[y])
            {
                deg[y]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<k;i++)
    {
        x=wic[i].first;
        w=wic[i].second;
        if(now[x]<w)
        {
            ans++;
        }
        else if(deg[x]>1)
        {
            deg[x]--;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
