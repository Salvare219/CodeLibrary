#include <bits/stdc++.h>
using namespace std;

const int MAXN=105;
int next[MAXN*4],head[MAXN],to[MAXN*4],mm;
int las[MAXN*4],col[MAXN*2];
int pre[MAXN];
bool inq[MAXN*4];
void add(int x,int y)
{
    next[mm]=head[x];to[mm]=y;head[x]=mm++;
    next[mm]=head[y];to[mm]=x;head[y]=mm++;
}
void del(int x,int y)
{
    mm-=2;
    head[x]=next[head[x]];
    head[y]=next[head[y]];
}
bool dfs(int s,int p,int z,int f)
{
    int y;
    for(int i=head[s];~i;i=next[i])
        if((y=to[i])!=p&&col[i>>1]==f)
        {
            pre[y]=i^1;
            if(y==z||dfs(y,s,z,f))
                return 1;
        }
    return 0;
}
bool insert(int x,int y)
{
    if(x==y)return 0;
    queue<int>q;
    int h=mm>>1,px=x,py=y;
    memset(inq,0,sizeof(inq));
    q.push(mm);inq[mm]=1;
    q.push(mm|1);inq[mm|1]=1;
    add(x,y);col[h]=2;
    while(!q.empty())
    {
        int f=q.front(),z=f&1,g;
        x=to[f];y=to[f^1];
        q.pop();
        if(!dfs(x,0,y,z))
        {
            while((f>>1)!=h)
                col[f>>1]^=1,f=las[f],z^=1;
            col[h]=z;
            return 1;
        }
        while(y!=x)
        {
            if(inq[g=(pre[y]|1)&~z]==0)
                inq[g]=1,las[g]=f,q.push(g);
            y=to[pre[y]];
        }
    }
    del(px,py);
    return 0;
}
void init()
{
    mm=0;
    memset(head,0xff,sizeof(head));
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m,x,y,cnt=0;init();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d",&x,&y),cnt+=insert(x+1,y+1);
        printf("Case %d: %s\n",ti++,cnt==2*n-2?"YES":"NO");
    }
    return 0;
}
