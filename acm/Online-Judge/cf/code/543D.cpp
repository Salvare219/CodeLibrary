#include<bits/stdc++.h>
using namespace std;


const int mod=1000000007;
vector<int>gra[200050];
long long dp[200050][2];
long long pow_mod(long long a,long long b)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=a*c%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
void dfs(int s)
{
    int y;
    long long s0=1,s1=1;
    for(int i=0;i<gra[s].size();i++)
    {
        dfs(y=gra[s][i]);
        s0=(s0*dp[y][0])%mod;
        s1=(s1*(dp[y][0]+dp[y][1]))%mod;
    }
    dp[s][0]=s0;
    dp[s][1]=s1;
}
long long ans[200050];
long long pre[400050][2],las[400050][2];
int tot;
void dfs2(int s,long long p0,long long p1)
{
    int y;
    long long s0=p0,s1=p0+p1;
    pre[tot][0]=pre[tot][1]=1;
    las[tot+(int)gra[s].size()][0]=las[tot+(int)gra[s].size()][1]=1;
    for(int i=0;i<gra[s].size();i++)
    {
        y=gra[s][i];
        pre[tot+i+1][0]=pre[tot+i][0]*dp[y][0]%mod;
        pre[tot+i+1][1]=pre[tot+i][1]*(dp[y][0]+dp[y][1])%mod;
    }
    for(int i=gra[s].size()-1;i>-1;i--)
    {
        y=gra[s][i];
        las[tot+i][0]=las[tot+i+1][0]*dp[y][0]%mod;
        las[tot+i][1]=las[tot+i+1][1]*(dp[y][0]+dp[y][1])%mod;
    }
    ans[s]=pre[tot+gra[s].size()][1]*s1%mod;
    for(int i=0;i<gra[s].size();i++)
    {
        y=gra[s][i];
        long long f0=pre[tot+i][0]*las[tot+i+1][0]%mod;
        long long f1=pre[tot+i][1]*las[tot+i+1][1]%mod;
        tot+=gra[s].size()+1;
        dfs2(y,f0*s0%mod,f1*s1%mod);
        tot-=gra[s].size()+1;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        gra[x].push_back(i+1);
    }
    dfs(1);
    dfs2(1,1,0);
    for(int i=1;i<=n;i++)
        printf("%d ",(int)ans[i]);
    puts("");
    return 0;
}
