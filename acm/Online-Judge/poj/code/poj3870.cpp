//#include<bits/stdc++.h>

#include<cstdio>

#include<cmath>

#include<algorithm>

#include<cstring>

#include<cstdlib>

#include<string>

#include<vector>

#include<set>

#include<iostream>

using namespace std;





struct edge

{

    int y,c,next;

    edge(){}

    edge(int y_,int c_,int n_){y=y_,c=c_,next=n_;}

}e[900005];

int head[20005];

int nn,mm;

int d[20005],cont[20005],q[20005];

int pre[20005],cur[20005];

bool vis[20005];

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

int in[500];

int out[500];

int f;

vector<int>ans[500000];

int n;

void dfs(int s)

{

    ans[f].push_back(s);

    for(int i=head[s];~i;i=e[i].next)

        if((i&1)==0&&e[i^1].c>=0&&e[i].y<=n)

        {

            e[i^1].c--;

            dfs(e[i].y);

            return;

        }

    return;

}

int main()

{

    scanf("%d",&n);

    mm=0;nn=n+4;

    for(int i=1;i<=nn;i++)head[i]=-1;

    int s=n+1,t=n+2,ps=n+3,pt=n+4,sum=0;

    for(int i=1;i<=n;i++)

    {

        int x,y;scanf("%d",&x);

        sum+=x;out[i]=x;

        add(ps,i,5000000);

        add(i,pt,5000000);

        for(int j=0;j<x;j++)

            scanf("%d",&y),in[y]++,add(i,y,5000000);

    }

    for(int i=1;i<=n;i++)

        if(in[i]>out[i])add(s,i,in[i]-out[i]);

        else if(in[i]<out[i])add(i,t,out[i]-in[i]);

    SAP(s,t);

    add(pt,ps,5000000);

    SAP(s,t);

    for(int i=head[ps];~i;i=e[i].next)

        if(e[i].y<=n)

        {

            while(e[i^1].c--)

                dfs(e[i].y),f++;

        }

    printf("%d\n",f);

    for(int i=0;i<f;i++)

        for(int j=0;j<ans[i].size();j++)

            printf("%d%c",ans[i][j],j==(ans[i].size()-1)?10:32);

    return 0;

}

