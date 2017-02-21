class Solution(object):
    def minDistance(self, s1, s2):
        n=len(s1)
        m=len(s2)
        dp=[[100000 for row in range(m+5)] for col in range(n+5)]
        dp[0][0]=0
        for i in xrange(n+1):
            for j in xrange(m+1):
                if i<n and j<m and s1[i]==s2[j]:
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j])
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1)
                dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1)
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1)
        return dp[n][m]