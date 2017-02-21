class Solution:
    # @param {integer[]} nums1
    # @param {integer} m
    # @param {integer[]} nums2
    # @param {integer} n
    # @return {void} Do not return anything, modify nums1 in-place instead.
    def merge(self, nums1, m, nums2, n):
        t=[]
        p1=p2=0
        while p1<m or p2<n:
            if p1==m:
                t.append(nums2[p2])
                p2+=1
            elif p2==n:
                t.append(nums1[p1])
                p1+=1
            else:
                if nums1[p1]>nums2[p2]:
                    t.append(nums2[p2])
                    p2+=1
                else:
                    t.append(nums1[p1])
                    p1+=1
        for i in xrange(len(t)):
            nums1[i]=t[i]
        
            
            
            