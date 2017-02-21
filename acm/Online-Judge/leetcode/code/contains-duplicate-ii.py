class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        n=len(nums)
        pos={}
        for i in xrange(n):
            if pos.get(nums[i])==None:
                pos[nums[i]]=i
            else:
                if i-pos[nums[i]]<=k:
                    return True
                pos[nums[i]]=i
        return False