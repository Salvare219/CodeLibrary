class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        n=len(s)
        ans=''
        for i in xrange(n):
            f=-1
            for j in xrange(min(i+1,n-i)):
                if s[i-j]!=s[i+j]:
                    break
                else:
                    f=j
            if 2*f+1>len(ans):
                ans=s[i-f:i+f+1]
        for i in xrange(n-1):
            f=-1
            for j in xrange(min(i+1,n-i-1)):
                if s[i-j]!=s[i+j+1]:
                    break
                else:
                    f=j
            print(f)
            if 2*(f+1)>len(ans):
                print('zz')
                ans=s[i-f:i+f+2]
        return ans
        
        
        