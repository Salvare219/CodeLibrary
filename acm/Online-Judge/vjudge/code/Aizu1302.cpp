#include <bits/stdc++.h>
using namespace std;


int s[130];
int dp[4000][4000];
bool v[4000][4000];
int how[4000];
int n,m;
int dfs(int x,int y)
{
    if(v[x][y])return dp[x][y];
    v[x][y]=1;
    int ty=0,u=-1;
    for(int i=0;i<m;i++)
        if((s[i]&x)==y)
        {
            int z=s[i]^y;
            how[z]++;
            if(z!=u)ty++,u=z;
        }
    for(int i=0;i<m;i++)
        if((s[i]&x)==y)
            how[s[i]^y]=0;
    if(ty==1)
        return dp[x][y]=0;
    else
    {
        int sum=1000000;
        for(int i=0;i<n;i++)
            if(((1<<i)&x)==0)
                sum=min(sum,1+max(dfs((1<<i)|x,y),dfs((1<<i)|x,(1<<i)|y)));
        return dp[x][y]=sum;
    }

}
int main()
{
    while(scanf("%d%d",&n,&m)&&n)
    {
        char f[130];
        for(int i=0;i<m;i++)
        {
            int z=0;
            scanf("%s",f);
            for(int j=0;j<n;j++)
                z|=f[j]-'0'<<j;
            s[i]=z;
        }
        int lim=1<<n;
        for(int i=0;i<lim;i++)
            for(int j=0;j<lim;j++)
                v[i][j]=0;
        printf("%d\n",dfs(0,0));
    }
    return 0;
}
