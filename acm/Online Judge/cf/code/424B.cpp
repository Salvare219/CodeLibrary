#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Point
{
    int x,y,w;
    bool operator<(const Point&a)const{return 1ll*x*x+1ll*y*y<1ll*a.x*a.x+1ll*a.y*a.y;}
}po[100000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&po[i].x,&po[i].y,&po[i].w);
    sort(po,po+n);
    int sum=1000000-k,now=0;
    long long dis=-1;
    for(int i=0;i<n;i++)
    {
        now+=po[i].w;
        if(now>=sum)
        {
            dis=po[i].x*po[i].x+po[i].y*po[i].y;
            break;
        }
    }
    if(dis!=-1)printf("%.10f\n",sqrt(1.0*dis));
    else puts("-1");
    return 0;
}
