#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char s[55],t[55];
bool dp[51][51][51][51];
int main()
{
    while(gets(s))
    {
        gets(t);
        int n=strlen(s),m=strlen(t);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<n;k++)
                    for(int l=0;l<m;l++)
                        dp[i][j][k][l]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][0][j][0]=dp[i][1][j][0]=dp[i][0][j][1]=1;
        int ans=0;
        for(int l1=0;l1<=n;l1++)
            for(int l2=0;l2<=m;l2++)
                for(int i=0;i+l1<=n;i++)
                    for(int j=0;j+l2<=m;j++)
                    {
                        bool &x=dp[i][l1][j][l2];
                        if(s[i]==s[i+l1-1])
                            x|=dp[i+1][l1-2][j][l2];
                        if(s[i]==t[j+l2-1])
                            x|=dp[i+1][l1-1][j][l2-1];
                        if(t[j]==s[i+l1-1])
                            x|=dp[i][l1-1][j+1][l2-1];
                        if(t[j]==t[j+l2-1])
                            x|=dp[i][l1][j+1][l2-2];
                        if(x)
                            ans=max(ans,l1+l2);//,printf("%d %d %d %d\n",i,i+l1,j,j+l2);
                    }
        printf("%d\n",ans);
    }
    return 0;
}
