class Solution:
    # @param nums, an integer[]
    # @return an integer
    def findPeakElement(self, nums):
        n=len(nums)
        if n==1:
            return 0
        if nums[0]>nums[1]:
            return 0
        if nums[n-1]>nums[n-2]:
            return n-1
        l=1
        r=n-1
        while r>l:
            mid=r+l>>1
            if nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]:
                return mid
            elif nums[mid]>nums[mid+1]:
                r=mid
            else:
                l=mid