class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        ans=[]
        nums.append(-41214)
        n=len(nums)
        las=ch=nums[0]
        for i in range(1,n):
            if ch+1==nums[i]:
                ch+=1
            else:
                if las==nums[i-1]:
                    ans.append("%d"%las)
                else:
                    ans.append("%d"%las+"->"+"%d"%nums[i-1])
                las=ch=nums[i]
        return ans