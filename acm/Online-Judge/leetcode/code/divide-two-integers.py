class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        mp={}
        for i in xrange(len(nums)):
            x=nums[i]
            if mp.get(target-x)!=None:
                return [mp[target-x],i+1]
            if mp.get(x)==None:
                mp[x]=i+1