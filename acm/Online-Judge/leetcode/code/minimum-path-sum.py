
def comp(x,y):
    s1="%d%d"%(x,y)
    s2="%d%d"%(y,x)
    if s1<s2:
        return 1
    else:
        return -1

class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        nums.sort(cmp=comp)
        ans=''
        for x in nums:
            ans+="%d"%x
        return "%d"%int(ans)