bool dp[4205][4205];
class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=0;
        dp[0][0]=1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(dp[i][j])
                {
                    if(s[i]=='?')
                        dp[i+1][j+1]=1;
                    if(s[i]=='*')
                        dp[i][j+1]=1,dp[i+1][j]=1;
                    if(p[j]=='?')
                        dp[i+1][j+1]=1;
                    if(p[j]=='*')
                        dp[i+1][j]=1,dp[i][j+1]=1;
                    if(s[i]==p[j])
                        dp[i+1][j+1]=1;
                }
        return dp[n][m];
    }
};