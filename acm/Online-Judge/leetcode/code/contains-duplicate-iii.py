class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        c=[]
        n=len(height)
        for i in xrange(n):
            c.append([height[i],i])
        c.sort(reverse=True)
        l=n-1
        r=0
        ans=0
        for i in xrange(n):
            l=min(c[i][1],l)
            r=max(c[i][1],r)
            ans=max(ans,max(r-c[i][1],c[i][1]-l)*c[i][0])
        return ans
            
            
            