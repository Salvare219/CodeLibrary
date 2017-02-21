#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> gra[100050];
int a[100050],n;
long long dp[100050][2];
bool fl;
bool dfs(int s,int p)
{
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            if(dfs(gra[s][i],s)) return 1;
        }
    long long g=-1,t=0,b,con=0;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            if(g==-1)
            {
                if(dp[gra[s][i]][1]==0) return 1;
                g=dp[gra[s][i]][1];
                t=dp[gra[s][i]][0];
            }
            else
            {
                if(dp[gra[s][i]][1]==0) return 1;
                g=g/__gcd(g,dp[gra[s][i]][1])*dp[gra[s][i]][1];
                b=min(dp[gra[s][i]][0],t);
                t=b-b%g;
            }
            con++;
        }
    if(con==0) dp[s][0]=a[s],dp[s][1]=1;
    else dp[s][0]=t*con+a[s],dp[s][1]=g*con;
    return 0;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%d",&n);
    int x,y;
    long long sum=0;
    for(int i=0;i<n;i++)
        scanf("%d",a+i+1),sum+=a[i+1];
    for(int i=1;i<n;i++)
        scanf("%d%d",&x,&y),gra[x].push_back(y),gra[y].push_back(x);
    if(dfs(1,0)) printf("%I64d\n",sum);
    else printf("%I64d",sum-dp[1][0]);
    return 0;
}


