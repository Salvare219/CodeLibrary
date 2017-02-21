class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(self, dig):
        n=len(dig)
        f=0
        for i in range(n-1,-1,-1):
            if dig[i]!=9:
                dig[i]+=1
                f=1
                break
            else:
                dig[i]=0
        if f==0:
            dig.insert(0,1);
        return dig