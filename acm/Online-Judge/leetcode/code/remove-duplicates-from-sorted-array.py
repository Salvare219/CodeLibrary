class Solution:
    # @param {string} s
    # @return {boolean}
    def isPalindrome(self, s):
        t=[]
        for x in s:
            if 'a'<=x and x<='z':
                t.append(x)
            if 'A'<=x and x<='Z':
                t.append(chr(ord(x)-ord('A')+ord('a')))
            if '0'<=x and x<='9':
                t.append(x)
        n=len(t)
        for i in xrange(n/2):
            if t[i]!=t[n-i-1]:
                return False
        return True