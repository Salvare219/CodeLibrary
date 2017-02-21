#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int x,y,w;
    p(int x_=0,int y_=0,int w_=0){x=x_,y=y_,w=w_;}
    bool operator<(p a)const{return w<a.w;}
}e[2][100050];
int n,m,k,a,b,ans;
int com[50050];
int find(int s)
{
    return s==com[s]?s:com[s]=find(com[s]);
}
bool add(int y,int h,int w)
{
    int tx,ty;
    tx=find(e[h][y].x);
    ty=find(e[h][y].y);
    if(tx!=ty)
    {
        com[tx]=ty;
        ans+=e[h][y].w+w;
        return 0;
    }
    return 1;
}
bool ok(int mid)
{
    for(int i=0;i<n;i++)com[i]=i;
    int x=0,y=0,c=0;ans=0;
    for(int i=1;i<n;i++)
    {
        bool f=1;
        while(f)
        {
            if(e[1][y].w<=e[0][x].w+mid)f=add(y++,1,0);
            else f=add(x++,0,mid),f?0:c++;
        }
    }
    return c>=k;
}
int main()
{
    int ti=1;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int x,y,w,c;a=b=0;
        for(int i=0;i<m;i++)
            scanf("%d%d%d%d",&x,&y,&w,&c),e[c][c?b++:a++]=p(x,y,w);
        sort(e[0],e[0]+a);sort(e[1],e[1]+b);
        e[0][a]=p(0,0,10000);e[1][b]=p(0,0,10000);
        int l=-100,r=100,mid;
        while(r>l)
        {
            mid=(r+l+1)/2;
            if(ok(mid))l=mid;
            else r=mid-1;
        }
        ok(l+1);
        printf("Case %d: %d\n",ti++,ans-k*(l+1));
    }
	return 0;
}
