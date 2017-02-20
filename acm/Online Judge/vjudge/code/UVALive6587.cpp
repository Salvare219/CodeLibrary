#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


struct Point_3
{
    int x[3],y[3];
}po[1000050];
int n,l;
const int inf=0x7fffffff;
bool solv(int a,int b,int c)
{
    int lx=-inf,ux=inf,ly=-inf,uy=inf,lz=-inf,uz=inf;
    int f=0;
    for(int i=0;i<n;i++)
        if(po[i].x[c]!=po[i].y[c])
        {
            f=1;
            lx=max(lx,po[i].x[a]-l);
            ux=min(ux,po[i].y[a]+l);
            ly=max(ly,po[i].x[b]-l);
            uy=min(uy,po[i].y[b]+l);
            lz=max(lz,po[i].x[c]);
            uz=min(uz,po[i].y[c]);
        }
    if(f==0)return 0;f=0;
    for(int i=0;i<n;i++)
        if(po[i].x[c]==po[i].y[c])
        {
            f=1;
            if(po[i].x[a]<lx)return 0;
            if(po[i].y[a]>ux)return 0;
            if(po[i].x[b]<ly)return 0;
            if(po[i].y[b]>uy)return 0;
            if(po[i].x[c]<lz)return 0;
            if(po[i].y[c]>uz)return 0;
        }
    return f;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x,y,z,x1,y1,z1;
            scanf("%d%d%d",&x,&y,&z);
            scanf("%d%d%d",&x1,&y1,&z1);
            po[i].x[0]=min(x,x1);po[i].y[0]=max(x,x1);
            po[i].x[1]=min(y,y1);po[i].y[1]=max(y,y1);
            po[i].x[2]=min(z,z1);po[i].y[2]=max(z,z1);
        }
        l=(po[0].y[0]-po[0].x[0]+po[0].y[1]-po[0].x[1]+po[0].y[2]-po[0].x[2])/2;
        if(solv(0,1,2)||solv(0,2,1)||solv(1,2,0))puts("YES");
        else puts("NO");
    }
    return 0;
}
