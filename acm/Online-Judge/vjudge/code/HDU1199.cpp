#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    int x,y,z,t;
    bool operator<(p a)const{return x<a.x;}
}q[3000];
int t[3000];
char l[4];
bool cmp(int a,int b)
{return q[a].t<q[b].t;}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%s",&q[i].x,&q[i].y,l);
            q[i].z=l[0]=='w';q[i].t=i+1;
        }
        q[n].x=0;q[n].y=0x7fffffff-1;
        q[n].z=0;q[n++].t=0;
        q[n].x=0x7fffffff-1;q[n].y=0x7fffffff-1;
        q[n].t=n;q[n++].z=0;
        sort(q,q+n);
        int k=1,now=-1,ty=0,las=-1,a1=-1,a2=0;
        t[0]=0;
        for(int i=1;i<n;)
        {
            now=min(q[t[0]].y+1,q[i].x);
            while(k&&q[t[0]].y<q[i].x)
            {
                while(k&&q[t[0]].y<now)
                    pop_heap(t,t+k--,cmp);
                if(now==q[i].x)break;
                if(q[t[0]].z!=ty)
                {
                    if(ty&&a2<now-las)a2=now-las,a1=las;
                    ty^=1;las=now;
                }
                now=min(q[t[0]].y+1,q[i].x);
            }
            while(i<n&&q[i].x==now)
                t[k++]=i++,push_heap(t,t+k,cmp);
            if(q[t[0]].z!=ty)
            {
                if(ty&&a2<now-las)a2=now-las,a1=las;
                ty^=1;las=now;
            }
        }
        if(a2)printf("%d %d\n",a1,a1+a2-1);
        else puts("Oh, my god");
    }
    return 0;
}
