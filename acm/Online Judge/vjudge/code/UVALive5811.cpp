#include<bits/stdc++.h>
using namespace std;


int C[5];
bool v[14][14][14][14][5][5];
double dp[14][14][14][14][5][5];
double dfs(int a,int b,int c,int d,int e,int f)
{
    if(v[a][b][c][d][e][f])return dp[a][b][c][d][e][f];
    v[a][b][c][d][e][f]=1;
    int t[5]={0,a,b,c,d},g=1;
    t[e]++;t[f]++;
    for(int i=1;i<=4;i++)
        if(t[i]<C[i])
            g=0;
    if(g)return dp[a][b][c][d][e][f]=0.0;
    int r1=13-a,r2=13-b,r3=13-c,r4=13-d,r5=2,rt,can=0;
    if(e)r5--;
    if(f)r5--;
    rt=r1+r2+r3+r4+r5;
    double sum=0.0;
    if(r1)sum+=1.0*r1/rt*(1.0+dfs(a+1,b,c,d,e,f)),can=1;
    if(r2)sum+=1.0*r2/rt*(1.0+dfs(a,b+1,c,d,e,f)),can=1;
    if(r3)sum+=1.0*r3/rt*(1.0+dfs(a,b,c+1,d,e,f)),can=1;
    if(r4)sum+=1.0*r4/rt*(1.0+dfs(a,b,c,d+1,e,f)),can=1;
    if(r5)
    {
        double gg=1e40;can=1;
        for(int i=1;i<=4;i++)
            if(e==0)gg=min(dfs(a,b,c,d,i,f),gg);
            else gg=min(dfs(a,b,c,d,e,i),gg);
        sum+=1.0*r5/rt*(1.0+gg);
    }
    if(can)return dp[a][b][c][d][e][f]=sum;
    else return dp[a][b][c][d][e][f]=1e40;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=4;i++)
            scanf("%d",C+i);
        memset(v,0,sizeof(v));dfs(0,0,0,0,0,0);
        double ans;
        if(dp[0][0][0][0][0][0]>1e20)ans=-1.0;
        else ans=dp[0][0][0][0][0][0];
        printf("Case %d: %.3f\n",ti++,ans);
    }
    return 0;
}
