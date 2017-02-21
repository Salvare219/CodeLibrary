class Solution:
    # @param {character[][]} matrix
    # @return {integer}
    def maximalSquare(self, matrix):
        n=len(matrix)
        if n==0:
            return 0
        m=len(matrix[0])
        sum=[[0 for col in range(m+1)] for row in range(n+1)]
        ans=0
        for i in xrange(n):
            for j in xrange(m):
                if matrix[i][j]=='1':
                    sum[i+1][j+1]=min(sum[i][j+1]+1,sum[i+1][j]+1,sum[i][j]+1)
                    ans=max(ans,sum[i+1][j+1])
        return ans*ans
        