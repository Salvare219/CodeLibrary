class Solution(object):
    def candy(self, rat):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n=len(rat)
        dp=[0]*n
        low=now=dp[0]=1
        for i in xrange(1,n):
            if rat[i]>rat[i-1]:
                now+=1
                dp[i]=now
            else:
                now=1
                dp[i]=now
        dp[n-1]=max(dp[n-1],1)
        now
        for i in xrange(n-2,-1,-1):
            if rat[i]>rat[i+1]:
                now+=1
                dp[i]=max(dp[i],now)
            else:
                now=1
                dp[i]=max(dp[i],now)
        return sum(dp)
                
                
                
                