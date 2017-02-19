#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,x,y;
    int tm=0,ts=999999999,v=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        tm=max(tm,x);ts=min(ts,x);
    }
    v=ts*2;
    tm=max(v,tm);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        if(tm>=x)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",tm);
    return 0;
}


