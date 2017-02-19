#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct point
{
    int x,y;
}po[51000];
bool vis[51000];
int dis(int a,int b,int c,int d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int x1,y1,x2,y2,a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    x1=min(a,c);x2=max(a,c);
    y1=min(b,d);y2=max(b,d);
    int k=0;
    for(int i=x1;i<=x2;i++)
    {
        po[k].x=i;po[k++].y=y1;
        po[k].x=i;po[k++].y=y2;
    }
    for(int i=y1+1;i<y2;i++)
    {
        po[k].x=x1;po[k++].y=i;
        po[k].x=x2;po[k++].y=i;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int j=0;j<k;j++)
            if(vis[j]==0)
            {
                if(dis(a,b,po[j].x,po[j].y)<=c*c)
                    vis[j]=1;
                if(vis[9])
                    int s=0;
            }
    }
    int ans=0;
    for(int i=0;i<k;i++)
        if(vis[i]==0) ans++;
    printf("%d\n",ans);
    return 0;
}


