class Solution:
    # @param {integer} n
    # @return {boolean}
    def solv(self,n):
        sum=0
        while n:
            sum+=(n%10)*(n%10)
            n/=10
        return sum
    def isHappy(self, n):
        st=set()
        while n not in st:
            st.add(n)
            n=self.solv(n)
            if n==1:
                return True
        return False
        