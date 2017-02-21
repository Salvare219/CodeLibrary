class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
    	n=len(s)
    	f=ans=0
    	for i in xrange(n):
    		if s[i]==' ':
    			f=0
    		else:
    			if f==0:
    				f=1
    				ans=1
    			else:
    				ans=ans+1
    	return ans

