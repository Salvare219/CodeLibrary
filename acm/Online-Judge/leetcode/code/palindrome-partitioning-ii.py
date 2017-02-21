class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, mat, target):
        n=len(mat)
        if n==0:
            return False
        m=len(mat[0])
        x=n-1
        y=0
        while x>=0 and y<m:
            if mat[x][y]>target:
                x-=1
            elif mat[x][y]<target:
                y+=1
            else:
                return True
        return False
        