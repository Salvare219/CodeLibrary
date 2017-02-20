#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
//    freopen("1.txt", "r", stdin);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m,sum=0,x,y;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;sum^=y,i++)
            for(int j=y=0;j<m;j++)
                scanf("%d",&x),y+=x;
        printf("Case %d: ",ti++);
        puts(sum?"Alice":"Bob");
    }
    return 0;
}
