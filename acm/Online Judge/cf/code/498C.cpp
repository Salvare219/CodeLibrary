#include <bits/stdc++.h>
using namespace std;


int a[200];
int prim[100050],k;
bool v[100050];
void cal()
{
	for(int i=2;i<100000;i++)
	{
		if(v[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<100000;j++)
		{
			v[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
struct edge
{
    int y,c,next;
    edge(){}
    edge(int y_,int c_,int n_){y=y_,c=c_,next=n_;}
}e[1000005];
int head[100005];
int nn,mm;
int d[100005],cont[100005],q[100005];
int pre[100005],cur[100005];
bool vis[100005];
void bfs(int s)
{
    int x,to,tail=1,front=0;
    for(int i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;
    d[s]=0;cont[0]=1;q[0]=s;vis[s]=1;
    while(front<tail)
        for(int i=head[x=q[front++]];i!=-1;i=e[i].next)
            if(!vis[to=e[i].y] && e[i^1].c)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                q[tail++]=to;
                cont[d[to]]++;
            }
}
int SAP(int s,int t)
{
	if(s==t) return 0x7fffffff;
    bfs(t);pre[s]=-1;
    int ans=0,x=s,y,len=0,flow,back;
    while(d[s]<nn)
    {
        y=-1;
        for(int i=cur[x];i!=-1;i=e[i].next)
            if(e[i].c && d[x]==d[e[i].y]+1)
            {
                y=e[i].y;
                cur[x]=i;
                break;
            }
        if(y!=-1)
        {
            pre[y]=x;x=y;
            if(x==t)
            {
                flow=0x3fffffff;
                for(y=pre[y];y!=-1;y=pre[y])
                    if(flow>=e[cur[y]].c) flow=e[cur[y]].c,back=y;
                for(x=pre[x];x!=-1;x=pre[x])
                    e[cur[x]^1].c+=flow,e[cur[x]].c-=flow;
                ans+=flow;x=back;
            }
        }
        else
        {
            y=nn;
            for(int i=head[x];i!=-1;i=e[i].next)
                if(e[i].c && y>d[e[i].y])
                    y=d[e[i].y],cur[x]=i;
            cont[d[x]]--;
            if(cont[d[x]]==0) break;
            cont[d[x]=y+1]++;
            if(x!=s) x=pre[x];
        }
    }
    return ans;
}
void add(int x,int y,int c)
{
    e[mm]=edge(y,c,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}
vector<pair<int,int> >pm[200];
int sa[100005];
int lin[200][200];
int main()
{
    //freopen("1.txt","r",stdin);
    cal();
    int n,m,xx,yy;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&xx,&yy);
        xx--;yy--;
        if(xx&1)lin[xx][yy]=1;
        if(yy&1)lin[yy][xx]=1;
    }
    int s=1,t=2;
    memset(head,-1,sizeof(head));
    mm=0;nn=3;
    for(int i=0;i<n;i++)
    {
        for(int j=0;1ll*prim[j]*prim[j]<=a[i]&&j<k;j++)
            if(a[i]%prim[j]==0)
            {
                int cnt=0;
                do cnt++,a[i]/=prim[j];
                while(a[i]%prim[j]==0);
                pm[i].push_back(make_pair(prim[j],nn));
                if(i&1)
                    add(s,nn,cnt);
                else
                    add(nn,t,cnt);
                nn++;
            }
        if(a[i]>1)
        {
            pm[i].push_back(make_pair(a[i],nn));
            if(i&1)
                add(s,nn,1);
            else
                add(nn,t,1);
            nn++;
        }
    }
    nn--;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(lin[i][j])
            {
                for(int x=0;x<pm[i].size();x++)
                    for(int y=0;y<pm[j].size();y++)
                        if(pm[i][x].first==pm[j][y].first)
                        {
                            add(pm[i][x].second,pm[j][y].second,1000000);
                        }
            }
    printf("%d\n",SAP(s,t));
    return 0;
}

