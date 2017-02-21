class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def canJump(self, nums):
        to=0
        for i in xrange(len(nums)):
            to=max(to,i+nums[i])
            if to==i:
                break
        to=min(to,len(nums)-1)
        return to==len(nums)-1