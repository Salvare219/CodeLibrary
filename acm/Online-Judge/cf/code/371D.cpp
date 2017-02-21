#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long a[300000];
struct ps
{
    long long has;
    int nex;
}l[300000];
int find(int s)
{
    return l[s].has!=a[s]?s:l[s].nex=find(l[s].nex);
}
void por(int x,int y)
{
    if(l[x].has+y>a[x])
    {
        por(l[x].nex,y-(a[x]-l[x].has));
        l[x].has=a[x];
    }
    else l[x].has+=y;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i),l[i].has=0,l[i].nex=i+1;
    a[n]=99999999;
    a[n]*=a[n];
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        scanf("%d",&x);
        if(x==1)
        {
            scanf("%d%d",&y,&z);y--;
            if(a[y]-l[y].has>=z)l[y].has+=z;
            else
            {
                long long f=a[y]-l[y].has;
                l[y].has=a[y];
                por(find(y),z-f);
            }
        }
        else
        {
            scanf("%d",&y);y--;
            printf("%d\n",l[y].has);
        }
    }
    return 0;
}
