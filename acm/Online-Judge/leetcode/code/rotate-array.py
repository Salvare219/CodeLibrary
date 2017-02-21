class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {void} Do not return anything, modify nums in-place instead.
    def rotate(self, nums, k):
        n=len(nums)
        k%=n
        for i in xrange(k):
            nums.insert(0,nums[n-1])
            nums.pop()
        