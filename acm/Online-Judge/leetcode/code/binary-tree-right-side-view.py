class Solution(object):
    def findRepeatedDnaSequences(self, s):
        n=len(s)
        if n<11:
            return []
        st=set()
        has=0
        mp={}
        mp['A']=0
        mp['C']=1
        mp['G']=2
        mp['T']=3
        for i in xrange(10):
            has=has<<2|mp[s[i]]
        st.add(has)
        ans=set()
        for i in xrange(10,n):
            has=has<<2|mp[s[i]]
            has&=(1<<20)-1
            if has in st:
                ans.add(s[i-9:i+1])
            st.add(has)
        return list(ans)