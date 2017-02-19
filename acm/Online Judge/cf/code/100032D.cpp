#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct p
{
    int x,y;
    bool operator<(const p&a)const
    {
        return x<a.x;
    }
}po[100050];
int main()
{
    freopen("millenium.in","r",stdin);
    freopen("millenium.out","w",stdout);
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&po[i].x,&po[i].y);
    }
    sort(po,po+n);
    long long sum=0,we,las=0;
    int p=0;
    for(int i=0;i<n;)
    {
        p=i;
        we=(po[i].x-las)*b;
        sum=max(0ll,sum-we);
        while(i<n&&po[p].x==po[i].x)
        {
            sum++;
            i++;
        }
        las=po[p].x;
    }
    we=po[n-1].x-1+(sum+b-1)/b;
    printf("%I64d\n",we);
    return 0;
}
