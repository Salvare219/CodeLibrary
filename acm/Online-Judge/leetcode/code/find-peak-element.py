class Solution(object):
# @param nums, an integer[]
# @return an integer
    def findPeakElement(self, nums):
        if len(nums)==1:
            return 0
        x=0
        while(x<len(nums)):
            if (x==0 and nums[x]>nums[x+1]) or (x==len(nums)-1 and nums[x]>nums[x-1]) or (nums[x]>nums[x-  1] and nums[x]>nums[x+1]):
                return x
            x+=1