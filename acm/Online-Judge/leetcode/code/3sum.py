class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def threeSum(self, num):
        mp={}
        n=len(num)
        ans=[]
        num.sort()
        l1=-3214421
        for i in xrange(n):
            if l1!=num[i]:
                l1=num[i]
                l2=-312414
                j=i+1
                p=n-1
                while j<p:
                    if l2!=num[j]:
                        l2=num[j]
                        while p>j and num[i]+num[j]+num[p]>0:
                            p=p-1
                        if p>j and num[i]+num[j]+num[p]==0:
                            ans.append([num[i],num[j],num[p]])
                    j=j+1
        return ans