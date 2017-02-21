class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        sum=0
        while n:
            if n&1:
                sum+=1
            n>>=1
        return sum