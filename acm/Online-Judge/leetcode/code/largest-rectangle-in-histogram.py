class Solution(object):
    def minWindow(self, s, t):
        mp={}
        n=len(s)
        for x in t:
            if x not in mp:
                mp[x]=0
            mp[x]+=1
        p=sum=0
        f='0'*(n+1)
        tot=len(mp)
        for i in xrange(n):
            while p<n and sum<tot:
                if s[p] in mp:
                    if mp[s[p]]==1:
                        sum+=1
                    mp[s[p]]-=1
                p+=1
            if sum==tot and p-i<len(f):
                f=s[i:p]
            if s[i] in mp:
                if mp[s[i]]==0:
                    sum-=1
                mp[s[i]]+=1
        if len(f)>n:
            return ''
        else:
            return f
        