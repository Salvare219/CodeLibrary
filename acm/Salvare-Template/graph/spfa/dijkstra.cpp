#include<queue>
vector<pair<int,int> > gra[160005];
int dis[160005];
int nn;
bool vis[160005];
inline int Dijkstra(int s,int t)
{
    int mdis,mx,k=1,to,w;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(int i=1;i<=nn;i++) dis[i]=0x3fffffff,vis[i]=0;
    q.push(make_pair(0,s));dis[s]=0;
    while(!q.empty())
    {
        mdis=q.top().first;
        mx=q.top().second;q.pop();
        if(vis[mx]) continue;
        if(mx==t) return mdis;
        vis[mx]=1;
        for(int i=0;i<gra[mx].size();i++)
            if(dis[to=gra[mx][i].first]>(w=gra[mx][i].second)+mdis)
                dis[to]=w+mdis,q.push(make_pair(dis[to],to));
    }
    return -1;
}
