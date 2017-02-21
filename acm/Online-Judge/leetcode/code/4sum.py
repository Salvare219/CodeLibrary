class Solution(object):
    def fourSum(self, num, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        n=len(num)
        print n
        num.sort()
        las1=-41284912
        ans=[]
        for i in xrange(n-3):
            if num[i]!=las1:
                las1=num[i]
                las2=-41284912
                for j in xrange(i+1,n-2):
                    if num[j]!=las2:
                        las2=num[j]
                        k=j+1
                        p=n-1
                        f=num[i]+num[j]
                        las3=-41284912
                        while k<p:
                            if num[k]!=las3:
                                las3=num[k]
                                while p>k and f+num[k]+num[p]>target:
                                    p-=1
                                if k<p and f+num[k]+num[p]==target:
                                    ans.append([num[i],num[j],num[k],num[p]])
                            k+=1
        return ans
        
        
        