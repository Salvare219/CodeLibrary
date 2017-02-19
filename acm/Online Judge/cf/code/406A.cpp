#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int mat[1005][1005];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,sum=0;scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);
    for(int i=0;i<n;i++)
        sum^=mat[i][i];
    int q;scanf("%d",&q);
    while(q--)
    {
        int ty,x;
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d",&x);
            sum^=1;
        }
        else if(ty==2)
        {
            scanf("%d",&x);
            sum^=1;
        }
        else printf("%d",sum);
    }
    putchar(10);
    return 0;
}
