#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct p
{
    int x,y;
}po[200000];
bool cmp(p a,p b)
{return abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y);}
void ty(int y)
{
    if(y>0) printf("1 %d U\n",y);
    else printf("1 %d D\n",-y);
}
void tx(int y)
{
    if(y>0) printf("1 %d R\n",y);
    else printf("1 %d L\n",-y);
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        po[i].x=x;po[i].y=y;
    }
    sort(po,po+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        x=po[i].x;y=po[i].y;
        if(x==0) ans+=4;
        else if(y==0) ans+=4;
        else ans+=6;
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
    {
        x=po[i].x;y=po[i].y;
        if(x==0)
        {
            ty(y);printf("2\n");
            ty(-y);printf("3\n");
        }
        else if(y==0)
        {
            tx(x);printf("2\n");
            tx(-x);printf("3\n");
        }
        else
        {
            tx(x);ty(y);
            printf("2\n");
            ty(-y);tx(-x);
            printf("3\n");
        }
    }
    return 0;
}


