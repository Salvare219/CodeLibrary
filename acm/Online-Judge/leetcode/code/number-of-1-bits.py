class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        a=b=0
        for x in nums:
            c=a
            a=b+x
            b=max(c,b)
        return max(a,b)