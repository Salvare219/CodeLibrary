class Solution:
    # @param {integer} k
    # @param {integer} n
    # @return {integer[][]}
    def combinationSum3(self, k, n):
        ans=[]
        for i in xrange(1<<9):
            sum=0
            t=[]
            for j in xrange(9):
                if 1<<j&i:
                    sum+=j+1
                    t.append(j+1)
            if sum==n and len(t)==k:
                ans.append(t)
        return ans