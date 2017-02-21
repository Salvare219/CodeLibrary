class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        if numRows==0:
            return []
        ans=[[1]]
        for i in xrange(1,numRows):
            a=b=1
            t=[1]
            for j in xrange(1,i+1):
                a*=i-j+1
                b*=j
                t.append(a/b)
            ans.append(t)
        return ans