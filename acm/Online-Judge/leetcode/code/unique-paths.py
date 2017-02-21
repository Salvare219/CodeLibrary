class Solution:
    # @param {integer[][]} grid
    # @return {integer}
    def minPathSum(self, grid):
        n=len(grid)
        if n==0:
            return 0
        m=len(grid[0])
        dp=[[1000000 for col in range(m+1)] for row in range(n+1)]
        dp[0][1]=0
        for i in xrange(n):
            for j in xrange(m):
                dp[i+1][j+1]=min(dp[i][j+1],dp[i+1][j])+grid[i][j]
        return dp[n][m]