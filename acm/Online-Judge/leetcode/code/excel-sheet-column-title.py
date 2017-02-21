class Solution:
    # @param {string} s
    # @return {integer}
    def titleToNumber(self, s):
        sum=0
        for x in s:
            sum=sum*26+ord(x)-ord('A')+1
        return sum