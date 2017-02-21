class Solution:
    def solv(self,s):
        n=len(s)
        cnt=[0]*26
        for i in xrange(n):
            cnt[ord(s[i])-ord('a')]=cnt[ord(s[i])-ord('a')]+1
        return cnt
    def isAnagram(self, s, t):
        ca=self.solv(s)
        cb=self.solv(t)
        for i in xrange(26):
            if ca[i]!=cb[i]:
                return False
        return True
        