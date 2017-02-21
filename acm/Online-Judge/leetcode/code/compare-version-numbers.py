class Solution:
    # @param {integer} n
    # @return {string}
    def convertToTitle(self, n):
        s=''
        while n:
            n-=1
            s+=chr(n%26+ord('A'))
            n/=26
        return s[::-1]