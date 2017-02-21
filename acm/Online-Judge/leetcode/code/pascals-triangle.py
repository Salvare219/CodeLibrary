class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        t=list(set(nums))
        n=len(t)
        t.sort()
        for i in xrange(n):
            nums[i]=t[i]
        return len(t)