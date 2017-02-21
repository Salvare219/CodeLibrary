#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const int mod=1000000007;
vector<int>gra[100050];
int c[100050];
long long dp[100050][2];

void dfs(int s,int p)
{
    int y;
    long long a=0,b=1;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            dfs(y,s);
            a=(dp[y][1]*b+dp[y][0]*a)%mod;
            b=b*dp[y][0]%mod;
        }
    if(c[s])dp[s][1]=b,dp[s][0]=b;
    else dp[s][0]=a+b,dp[s][1]=a;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&x);
        gra[x].push_back(i);
        gra[i].push_back(x);
    }
    for(int i=0;i<n;i++)
        scanf("%d",c+i);
    dfs(0,-1);
    printf("%I64d\n",dp[0][1]);
    return 0;
}
