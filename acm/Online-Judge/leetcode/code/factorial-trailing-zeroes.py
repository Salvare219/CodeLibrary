class Solution:
    # @param {integer} n
    # @return {integer}
    def cal(self,n,k):
        sum=0
        while n:
            sum+=n/k
            n/=k
        return sum
    def trailingZeroes(self, n):
        return min(self.cal(n,2),self.cal(n,5))