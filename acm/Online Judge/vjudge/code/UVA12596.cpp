#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long dp[30][20];
int how[600];
char sm[6000];
char lib[15][15]={"ZERO","ONE"
,"TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
char dfs(int k,int re)
{
    if(re==0)return sm[k-1];
    for(int i=0;sm[i];i++)
        if(dp[re][how[sm[i]]]>=k)
        {
            strcpy(sm,lib[how[sm[i]]]);
            return dfs(k,re-1);
        }
        else k-=dp[re][how[sm[i]]];
    return 0;
}
int main()
{
    char o='A';
    for(int i=2;i<10;i++)
    {
        for(int j=0;j<3;j++)
            how[o++]=i;
        if(i==7||i==9)how[o++]=i;
    }
    for(int i=0;i<10;i++)dp[0][i]=1;
    for(int i=1;i<30;i++)
    {
        dp[i][2]=dp[i-1][8]+dp[i-1][9]+dp[i-1][6];
        dp[i][3]=dp[i-1][8]+dp[i-1][4]+dp[i-1][7]+2*dp[i-1][3];
        dp[i][4]=dp[i-1][3]+dp[i-1][6]+dp[i-1][7]+dp[i-1][8];
        dp[i][5]=dp[i-1][4]+dp[i-1][8]+2*dp[i-1][3];
        dp[i][6]=dp[i-1][4]+dp[i-1][7]+dp[i-1][9];
        dp[i][7]=dp[i-1][7]+dp[i-1][3]*2+dp[i-1][8]+dp[i-1][6];
        dp[i][8]=dp[i-1][4]*3+dp[i-1][3]+dp[i-1][8];
        dp[i][9]=dp[i-1][6]*2+dp[i-1][4]+dp[i-1][3];
    }
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",ti++);
        int n,k;scanf("%s%d%d",sm,&n,&k);
        printf("%c\n",dfs(k,n));
    }
    return 0;
}
