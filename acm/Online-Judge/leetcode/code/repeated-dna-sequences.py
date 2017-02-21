class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        cnt=0
        while m!=n:
            m>>=1
            n>>=1
            cnt+=1
        return n<<cnt
        