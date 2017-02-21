#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int y,c,f,next;
    edge(int y_=0,int c_=0,int f_=0,int n_=0){y=y_,c=c_,f=f_,next=n_;}
}e[2008000];
int head[2005];
int nn,mm;
int phi[2005],q[2005];
int s_,t_,cost_,tot_;
bool v[2005];
inline bool relable()
{
    int x,to,tail=1,front=0;
    for(int i=1;i<=nn;i++)v[i]=0,phi[i]=0x3fffffff;
    phi[t_]=0;q[0]=t_;
    while(tail!=front)
    {
        x=q[front++];v[x]=0;
        if(front>nn)front=0;
        for(int i=head[x];~i;i=e[i].next)
            if(e[i^1].c&&phi[to=e[i].y]>phi[x]-e[i].f)
            {
                phi[to]=phi[x]-e[i].f;
                if(v[to]==0)
                {
                    v[to]=1;
                    if(phi[to]<phi[q[front]])
                        front==0?front=nn:front--,q[front]=to;
                    else
                        q[tail++]=to,tail>nn?tail=0:0;
                }
            }
    }
    for(int i=1;i<=nn;i++)
        for(int j=head[i];~j;j=e[j].next)
            e[j].f+=phi[e[j].y]-phi[i];
    tot_+=phi[s_];
    return phi[s_]<0x3fffffff;
}
inline int aug(int s,int flow)
{
    if(s==t_)return cost_+=tot_*flow,flow;
    int res=flow,te;v[s]=1;
    for(int i=head[s];~i;i=e[i].next)
        if(!v[e[i].y]&&!e[i].f&&e[i].c)
        {
            res-=(te=aug(e[i].y,min(res,e[i].c)));
            e[i].c-=te;e[i^1].c+=te;
            if(!res)return flow;
        }
    return flow-res;
}
int cost_flow(int s,int t)
{
    cost_=tot_=0;s_=s;t_=t;
    do memset(v,0,sizeof(v));
    while(aug(s,0x3fffffff)||relable());
    return cost_;
}
inline void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}
int cal(int s)
{
    int c=0;
    while(s)c++,s-=s&-s;
    return c;
}
int a[300],vs[300];
int st[50],un[300];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);nn=2*n+4;mm=0;
    for(int i=1;i<=nn;i++)head[i]=-1;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),un[i-1]=a[i],add(i,i+n,1,-10000);
    sort(un,un+n);m=min(unique(un,un+n)-un,m);
    int s=nn-3,t=nn;add(s,s+1,m,0);add(t-1,t,m,0);
    for(int i=1;i<=n;i++)
    {
        add(s+1,i,1,cal(a[i]));
        add(i+n,t-1,1,0);
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]==a[i])add(i+n,j,1,0);
            else add(i+n,j,1,cal(a[j]));
        }
    }
    int k=1,x,ans=cost_flow(s,t);
    for(int i=head[s+1];~i;i=e[i].next)
        if(e[i].c==0&&e[i].y<=n)
            vs[e[i].y]=k++;
    for(int i=1;i<=n;i++)
        for(int j=head[i];~j&&vs[i]==0;j=e[j].next)
            if(e[j].y!=i+n&&e[j^1].c==0)
                vs[i]=vs[e[j].y-n];
    memset(st,-1,sizeof(st));
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(st[vs[i]]!=a[i])st[vs[i]]=a[i],sum++;
        sum++;
    }
    printf("%d %d\n",sum,ans+n*10000);
    memset(st,-1,sizeof(st));
    for(int i=1;i<=n;i++)
    {
        if(st[vs[i]]!=a[i])st[vs[i]]=a[i],printf("%c=%d\n",vs[i]+'a'-1,a[i]),sum++;
        printf("print(%c)\n",vs[i]+'a'-1);sum++;
    }
	return 0;
}