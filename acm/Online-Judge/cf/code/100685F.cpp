#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
double a[111111],p[111111];
int head[111111],cnt;
struct edge
{
	int to,nxt;
	edge(int _t=-1,int _n=-1) {to=_t;nxt=_n;}
}e[111111];
queue<int>q;
void addedge(int u,int v)
{
    e[cnt]=edge(v,head[u]);
    head[u]=cnt++;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
        cnt=0;
        while(!q.empty()) q.pop();
        memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i],&p[i]);
		for(int i=1;i<=m;i++)
		{
		    int u,v;
		    scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		int x,y;
		double f;
		scanf("%d%lf%d",&x,&f,&y);
		p[x]+=f;
		q.push(x);
		while(!q.empty())
        {
			x=q.front();q.pop();
			if(p[x]<=a[x]) continue;
			f=p[x]-a[x];
			p[x]=a[x];
			int w=0;
			for(int t=head[x];t!=-1;t=e[t].nxt) w++;
			f/=w;
			for(int t=head[x];t!=-1;t=e[t].nxt)
			{
				p[e[t].to]+=f;
				q.push(e[t].to);
			}
		}
		printf("%.10f\n",p[y]);
	}
	return 0;
}
