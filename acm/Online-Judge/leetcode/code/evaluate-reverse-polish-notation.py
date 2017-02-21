class Solution:
    # @param {string[]} tokens
    # @return {integer}
    def evalRPN(self, s):
        a=[]
        for x in s:
            n=len(a)
            if x=='+':
                a[n-2]+=a[n-1]
                a.pop()
            elif x=='-':
                a[n-2]-=a[n-1]
                a.pop()
            elif x=='*':
                a[n-2]*=a[n-1]
                a.pop()
            elif x=='/':
                a[n-2]=int(operator.truediv(a[n-2], a[n-1]))
                a.pop()
            else:
                a.append(int(x))
        return a[0]
                