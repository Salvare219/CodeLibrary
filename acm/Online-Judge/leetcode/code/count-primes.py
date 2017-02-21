class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        f=0
        if x<0:
            f=1
            x=-x
        a="%d"%x
        b=int(a[::-1])
        if b>(1<<31):
            return 0
        if f:
            b=-b
        return b