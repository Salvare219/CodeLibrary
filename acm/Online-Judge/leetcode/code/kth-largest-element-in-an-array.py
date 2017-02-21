class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLongestSubstring(self, s):
        n=len(s)
        ans=0
        st=set()
        p2=0
        for p1 in xrange(n):
            while p2<n and s[p2] not in st:
                st.add(s[p2])
                p2+=1
            ans=max(len(st),ans)
            st.remove(s[p1])
        return ans