#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


struct point
{
    int x,y,i;
    bool operator<(point p)const
    {
        return x!=p.x?x<p.x:y<p.y;
    }
}p[10050];
struct edge
{
    int x,y,w;
    bool operator<(edge p)const
    {
        return w<p.w;
    }
}e[40050];
int n,k,m,ans;
int a[10050],b[10050];
int bit[10050][2];
int query(int x)
{
    int s=0x3fffffff,f=-1;
    while(x<=m)
    {
        if(s>bit[x][0]) s=bit[x][0],f=bit[x][1];
        x+=x&-x;
    }
    return f;
}
void updat(int x,int val,int i)
{
    while(x)
    {
        if(bit[x][0]>val) bit[x][0]=val,bit[x][1]=i;
        x-=x&-x;
    }
}
int com[10050];
int find(int s)
{
    return s==com[s]?s:com[s]=find(com[s]);
}
void Manhattan()
{
    int pos,f,tot=0;
    for(int j=0;j<4;j++)
    {
        if(j==1||j==3) for(int i=0;i<n;i++) swap(p[i].x,p[i].y);
        else if(j==2) for(int i=0;i<n;i++) p[i].x=-p[i].x;
        sort(p,p+n);
        for(int i=0;i<n;i++)
            a[i]=b[i]=p[i].y-p[i].x;
        sort(b,b+n);
        m=unique(b,b+n)-b;
        for(int i=1;i<=m;i++)
            bit[i][0]=0x3fffffff,bit[i][1]=-1;
        for(int i=n-1;i>-1;i--)
        {
            pos=lower_bound(b,b+m,a[i])-b+1;
            f=query(pos);
            if(f!=-1)
            {
                e[tot].x=p[i].i;e[tot].y=p[f].i;
                e[tot++].w=p[f].x+p[f].y-p[i].x-p[i].y;
            }
            updat(pos,p[i].y+p[i].x,i);
        }
    }
    sort(e,e+tot);
    int cnt=0,x,y;
    for(int i=0;i<tot;i++)
    {
        x=find(e[i].x);y=find(e[i].y);
        if(x==y) continue;
        else
        {
            com[x]=y;
            cnt++;
            if(cnt==n-k)
            {
                ans=e[i].w;
                return ;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y),p[i].i=i,com[i]=i;
    Manhattan();
    printf("%d\n",ans);
    return 0;
}

