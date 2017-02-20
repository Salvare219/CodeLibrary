#include<bits/stdc++.h>
using namespace std;

int nn,mm;
vector<int> gra[2005];
int cap[2005][2005],fee[2005][2005];
int q[2005],p[2005],dis[2005];
bool vis[2005];
bool spfa(int s,int t)
{
    int to,tail=1,front=0;
    for(int i=1;i<=nn;i++) vis[i]=0,dis[i]=0x3fffffff;
    dis[s]=0;q[0]=s;
    while(tail!=front)
    {
        s=q[front++];vis[s]=0;
        if(front>nn)front=0;
        for(int i=0;i<gra[s].size();i++)
            if(cap[s][to=gra[s][i]]>0&&dis[to]>dis[s]+fee[s][to])
            {
                dis[to]=dis[s]+fee[s][to];p[to]=s;
                if(vis[to]==0)
                {
                    vis[to]=1;
                    if(dis[to]<dis[q[front]])
                        front==0?front=nn:front--,q[front]=to;
                    else
                        q[tail++]=to,tail>nn?tail=0:0;
                }
            }
    }
    if(dis[t]<0x3fffffff) return 1;
    else return 0;
}
int cost_flow(int s,int t)
{
	int ans=0,flow,x;
	while(spfa(s,t))
	{
	    flow=0x3fffffff;
		for(x=t;x!=s;x=p[x]) flow=min(flow,cap[p[x]][x]);
		for(x=t;x!=s;x=p[x])
			cap[x][p[x]]+=flow,cap[p[x]][x]-=flow,ans+=flow*fee[p[x]][x];
	}
	return ans;
}
void add(int x,int y,int c,int f)
{
    gra[x].push_back(y);
    gra[y].push_back(x);
    cap[x][y]=c;fee[x][y]=f;
    cap[y][x]=0;fee[y][x]=-f;
}
pair<int,int>qq[1005];
int main()
{
    int n,k,a,b,c;scanf("%d%d",&n,&k);
    nn=2*n+3;mm=0;
    int s=nn-2,t=nn;
    add(s,s+1,k,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);qq[i]=make_pair(a,a+b);
        add(i,i+n,1,-c);add(s+1,i,1,0);add(i+n,t,1,0);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(qq[i].second<=qq[j].first)add(i+n,j,1,0);
    cost_flow(s,t);
    for(int i=1;i<=n;i++)
        if(cap[i][i+n]==0)printf("1 ");
        else printf("0 ");
    putchar(10);
	return 0;
}