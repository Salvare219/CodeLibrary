class Solution:
    # @param {integer} numerator
    # @param {integer} denominator
    # @return {string}
    def fractionToDecimal(self, x, y):
        sig=0
        if (x<0 and y>0) or (x>0 and y<0):
            sig=1
        x=abs(x)
        y=abs(y)
        ans=''
        mp={}
        ct=0
        while x!=0 and x not in mp:
            if ct==1:
                ans+='.'
            mp[x]=len(ans)
            ans+="%d"%(x/y)
            x=x%y*10
            ct+=1
        if x in mp:
            z=mp[x]
            ans=ans[0:z]+'('+ans[z:len(ans)]+')'
        if ans=='':
            ans+='0'
        if sig:
            ans='-'+ans
        return ans