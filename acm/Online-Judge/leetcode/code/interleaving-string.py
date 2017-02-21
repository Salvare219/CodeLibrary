class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        n,m=len(s1),len(s2)
        if len(s3)!=n+m:
            return False
        dp=[[False for row in range(m+1)] for col in range(n+1)]
        dp[0][0]=True
        for i in xrange(n+1):
            for j in xrange(m+1):
                if dp[i][j]:
                    if i<n and i+j<n+m and s1[i]==s3[i+j]:
                        dp[i+1][j]=True
                    if j<m and i+j<n+m and s2[j]==s3[i+j]:
                        dp[i][j+1]=True
        return dp[n][m]