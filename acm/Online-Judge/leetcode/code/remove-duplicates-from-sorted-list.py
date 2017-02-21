class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self, n):
        if n==1:
            return 1
        if n==2:
            return 2
        a=1
        b=2
        for i in range(3,n+1):
            c=a+b
            a=b
            b=c
        return c