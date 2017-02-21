class Solution:
    # @param {integer} x
    # @return {boolean}
    def isPalindrome(self, x):
        s="%d"%x
        n=len(s)
        for i in xrange(n/2):
            if s[i]!=s[n-i-1]:
                return False
        return True