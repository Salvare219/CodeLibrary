class Solution:
    # @param {string} s
    # @return {boolean}
    def isValid(self, s):
        q=[]
        mp={}
        mp[']']='['
        mp[')']='('
        mp['}']='{'
        for x in s:
            if mp.get(x)!=None:
                if len(q)==0 or q[len(q)-1]!=mp[x]:
                    return False
                q.pop()
            else:
                q.append(x)
        return len(q)==0
            