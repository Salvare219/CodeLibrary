#include<bits/stdc++.h>
using namespace std;


const int mod=1000000000;
vector<int>gra[105];
long long dp[105][105][2];
long long te[105][2];
int n;
void dfs(int s,int p)
{
    int y;
    dp[s][1][1]=1;
    dp[s][0][0]=1;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            dfs(y,s);
            for(int j=0;j<=n;j++)
                te[j][0]=te[j][1]=0;
            for(int j=0;j<=n;j++)
            {
                for(int z=n-j;z>=0;z--)
                {
                    te[z+j][0]=(te[z+j][0]+dp[s][z][0]*(dp[y][j][0]+dp[y][j][1]))%mod;
                    te[z+j][1]=(te[z+j][1]+dp[s][z][1]*(dp[y][j][0]+dp[y][j][1]))%mod;
                    if(z&&j)te[z+j-1][1]=(te[z+j-1][1]+dp[s][z][1]*dp[y][j][1])%mod;
                }
            }
            for(int z=0;z<=n;z++)
                dp[s][z][0]=te[z][0],dp[s][z][1]=te[z][1];
        }
}
int main()
{
    freopen("subtrees.in","r",stdin);
    freopen("subtrees.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%I64d\n",(dp[1][i][0]+dp[1][i][1])%mod);
    return 0;
}
