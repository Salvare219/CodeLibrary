class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, v1, v2):
        l1=map(int,v1.split('.'))
        l2=map(int,v2.split('.'))
        while len(l1)>1 and l1[len(l1)-1]==0:
            l1.pop()
        while len(l2)>1 and l2[len(l2)-1]==0:
            l2.pop()
        c=min(len(l1),len(l2))
        for i in xrange(c):
            if l1[i]>l2[i]:
                return 1
            elif l1[i]<l2[i]:
                return -1
        if len(l1)<len(l2):
            return -1
        elif len(l1)>len(l2):
            return 1
        return 0