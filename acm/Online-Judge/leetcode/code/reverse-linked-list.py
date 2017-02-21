class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def c(self, x):
        mp={}
        k=1
        s=''
        n=len(x)
        for i in xrange(n):
            if mp.get(x[i])==None:
                mp[x[i]]=k
                k+=1
            s+=chr(mp[x[i]])
        return s
    def isIsomorphic(self, s, t):
        return self.c(s)==self.c(t)