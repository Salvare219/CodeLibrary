#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


int dp[2050][2050];
int las[2050];
char s[2050],t[2050];
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    s[0]='&';
    for(int i=1;i<=n;i++)
    {
        int now=m;
        for(int j=i;j>0;j--)
        {
            if(s[j]==t[now])
                now--;
            if(now==0)
            {
                las[i]=j;
                break;
            }
        }
    }
    dp[0][0]=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            int sb=j-(i-las[i]+1-m);
            if(las[i]>0&&sb>=0&&las[i]-1>=sb)
                dp[i][j]=max(dp[i][j],dp[las[i]-1][sb]+1);

            dp[i][j]=max(dp[i][j],dp[i-1][j]);

            if(j>0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]);

        }
    for(int i=0;i<=n;i++)
        printf("%d ",dp[n][i]);
    putchar(10);
    return 0;
}




