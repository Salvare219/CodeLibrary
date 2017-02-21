//#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;


struct edges
{
    int to,next,cost;
    edges(){}
    edges(int _t,int _n,int _c):to(_t),next(_n),cost(_c){}
}edger[100050],edge[100050];
int n,m,K;
int dist[1050];
int headr[1050],head[1050],Lr,L;
void dijkstra(int s)
{
    int x,y,w;
    priority_queue<pair<int,int> >q;
    for(int i=1;i<=n;i++)dist[i]=0x3fffffff;
    q.push(make_pair(dist[s]=0,s));
    while(!q.empty())
    {
        w=-q.top().first;
        x=q.top().second;
        q.pop();
        if(w!=dist[x])continue;
        for(int i=headr[x];~i;i=edger[i].next)
            if(dist[y=edger[i].to]>w+edger[i].cost)
            {
                dist[y]=w+edger[i].cost;
                q.push(make_pair(-dist[y],y));
            }
    }
}
int num[1050];
void add_edge(int x,int y,int w)
{
    edge[L]=edges(y,head[x],w);head[x]=L++;
    edger[Lr]=edges(x,headr[y],w);headr[y]=Lr++;
}
vector<pair<int,int> >pre;
int a_star(int s,int t)
{
    if(dist[s]==0x3fffffff)return -1;
    int x,y,w;
    priority_queue<pair<int,int> >q;
    pre.clear();
    q.push(make_pair(-dist[s],0));
    pre.push_back(make_pair(s,-1));
    while(!q.empty())
    {
        x=pre[q.top().second].first;
        w=-q.top().first-dist[x];
        q.pop();
        num[x]++;
        if(num[t]==K)return w;
        for(int i=head[x];~i;i=edge[i].next)
        {
            y=edge[i].to;
            q.push(make_pair(-w-edge[i].cost-dist[y],pre.size()));
            pre.push_back(make_pair(y,i^1));
        }
    }
    return -1;
}

int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    Lr=L=0;
    memset(head,-1,sizeof(head));
    memset(headr,-1,sizeof(headr));
    memset(num,0,sizeof(num));
    for(int i=0;i<m;i++)
    {
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        add_edge(u,v,x);
    }
    int s,t;
    scanf("%d%d%d",&s,&t,&K);
    dijkstra(t);
    if(s==t)K++;
    printf("%d\n",a_star(s,t));
	return 0;
}
