#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


int lo[100050][3];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m,s,f;
    scanf("%d%d%d%d",&n,&m,&s,&f);
    int dir=-1;
    if(s<f) dir=1;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&lo[i][0],&lo[i][1],&lo[i][2]);
    }
    int now=1,st=0;
    for(int i=s;i!=f;)
    {
        while(st<m && lo[st][0]<now) st++;
        if(lo[st][0]==now)
        {
            if((i+dir<=lo[st][2] && i+dir>=lo[st][1]) || (i<=lo[st][2] && i>=lo[st][1]))
            {
                putchar('X');
            }
            else
            {
                if(dir==1) putchar('R');
                else putchar('L');
                i+=dir;
            }
        }
        else
        {
            if(dir==1) putchar('R');
            else putchar('L');
            i+=dir;
        }
        now++;
    }
    putchar(10);
    return 0;
}
/*

int dp[10000][8];
char maz[3][10000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        scanf("%s",maz[i]);
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        dp[i+1][0]=dp[i][1]+dp[i][3];
        dp[i+1][1];
        dp[i+1][2];
        dp[i+1][3];
        dp[i+1][4];
        dp[i+1][5];
        dp[i+1][6];
        dp[i+1][7];
    }
    return 0;
}*/

