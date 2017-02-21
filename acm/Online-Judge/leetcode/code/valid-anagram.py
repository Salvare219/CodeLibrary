class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        a=b=1
        ans=[]
        for i in xrange(rowIndex+1):
            ans.append(a/b)
            a=a*(rowIndex-i)
            b=b*(i+1)
        return ans
        