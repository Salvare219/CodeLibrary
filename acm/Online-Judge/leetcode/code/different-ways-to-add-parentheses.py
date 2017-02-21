class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, tri):
        n=len(tri)
        if n==0:
            return 0
        for i in xrange(n-2,-1,-1):
            for j in xrange(i+1):
                tri[i][j]+=min(tri[i+1][j],tri[i+1][j+1])
        return tri[0][0]