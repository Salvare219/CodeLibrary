#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct p
{
    int x,y;
    bool operator<(p a)const{return a.x==x?y<a.y:x<a.x;}
}po[1005];
int n;
bool find(int x,int y)
{
    int l=0,r=n-1,s,t;
    while(l<r)
    {
        s=(l+r)>>1;
        if(po[s].x<x) l=s+1;
        else r=s;
    }
    if(po[r].x!=x) return 0;
    l=s=r;r=n-1;
    while(l<r)
    {
        t=(l+r)/2+1;
        if(po[t].x>x) r=t-1;
        else l=t;
    }
    t=l;
    while(s<t)
    {
        l=(s+t)>>1;
        if(po[l].y<y) s=l+1;
        else t=l;
    }
    return po[t].y==y;
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&po[i].x,&po[i].y);
        sort(po,po+n);
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(find(po[i].x+po[i].y-po[j].y,po[i].y-po[i].x+po[j].x) &&
                   find(po[j].x+po[i].y-po[j].y,po[j].y-po[i].x+po[j].x))
                    ans++;
                if(find(po[i].x-po[i].y+po[j].y,po[i].y+po[i].x-po[j].x) &&
                   find(po[j].x-po[i].y+po[j].y,po[j].y+po[i].x-po[j].x))
                    ans++;
            }
        printf("%d\n",ans/4);
    }
    return 0;
}
