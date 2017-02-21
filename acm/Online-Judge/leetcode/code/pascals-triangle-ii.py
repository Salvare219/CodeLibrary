class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        a=b=0
        n=len(nums)
        for i in xrange(n):
            if nums[i]==a:
                b=b+1
            else:
                if b==0:
                    a=nums[i]
                    b=1
                else:
                    b=b-1
        return a
        