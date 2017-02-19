#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;


vector<pair<int,int> >gra[40000];
int dis[40000];
int inq[40000];
int main()
{
    int k,n;scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        int d=min(y-x+1,k);
        gra[x+10000].push_back(make_pair(y+10001,d));
    }
    for(int i=0;i<20001;i++)
    {
        gra[i].push_back(make_pair(i+1,0));
        gra[i+1].push_back(make_pair(i,-1));
    }
    queue<int>q;
    q.push(0);
    for(int i=0;i<20002;i++)
        dis[i]=-(1<<30);
    dis[0]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        inq[x]=0;
        for(int i=0;i<gra[x].size();i++)
        {
            int y=gra[x][i].first,w=gra[x][i].second;
            if(dis[y]<dis[x]+w)
            {
                dis[y]=dis[x]+w;
                if(inq[y]==0)
                {
                    inq[y]=1;
                    q.push(y);
                }
            }
        }
    }
    printf("%d\n",dis[20001]);
    for(int i=0;i<20002;i++)
        if(dis[i+1]-dis[i]==1)
            printf("%d\n",i-10000);
    return 0;
}
