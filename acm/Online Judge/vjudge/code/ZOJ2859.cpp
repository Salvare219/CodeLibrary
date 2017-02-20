#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int num[305][305];
int dp[305][305][9][9];
void rmq_2d(int n,int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j][0][0]=num[i][j];
    for(int l1=1,x=0;l1<=n;l1<<=1,x++)
        for(int l2=1,y=0;l2<=m;l2<<=1,y++)
            for(int i=0;(x||y)&&i+l1<=n;i++)
                for(int j=0;j+l2<=m;j++)
                {
                    if(y==0)dp[i][j][x][y]=min(dp[i][j][x-1][y],dp[i+l1/2][j][x-1][y]);
                    else dp[i][j][x][y]=min(dp[i][j][x][y-1],dp[i][j+l2/2][x][y-1]);
                }
}
int to[305];
void pre_log()
{
    to[1]=0;
    for(int i=2;i<304;i+=2)
        to[i]=to[i+1]=to[i>>1]+1;
}
inline int query_2d(int x,int y,int x1,int y1)
{
    if(x>x1)swap(x,x1);
    if(y>y1)swap(y,y1);
    int m1=to[x1-x+1],m2=to[y1-y+1];
	//mid=to[r-l+1];
    int l1=1<<m1,l2=1<<m2;
    return min(min(dp[x][y][m1][m2],dp[x1-l1+1][y1-l2+1][m1][m2]),
               min(dp[x1-l1+1][y][m1][m2],dp[x][y1-l2+1][m1][m2]));
}
int main()
{
    int t;scanf("%d",&t);pre_log();
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&num[i][j]);
        rmq_2d(n,n);
        int x,y,x1,y1;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d%d%d",&x,&y,&x1,&y1);
            printf("%d\n",query_2d(x-1,y-1,x1-1,y1-1));
        }
    }
    return 0;
}
