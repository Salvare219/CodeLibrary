int dp[1000][1000];
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n=d.size(),m=d[0].size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=1000000;
        dp[n][m-1]=0;
        for(int i=n-1;i>-1;i--)
            for(int j=m-1;j>-1;j--)
                dp[i][j]=max(0,min(dp[i+1][j],dp[i][j+1])-d[i][j]);
        return dp[0][0]+1;
    }
};