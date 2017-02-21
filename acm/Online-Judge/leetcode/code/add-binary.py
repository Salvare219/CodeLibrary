ans=TreeNode(-1)

def solv(root,p,q):
    global ans
    t=0
    if root.val==p.val or root.val==q.val:
        t=t+1
    if root.left!=None:
        t=t+solv(root.left,p,q)
    if root.right!=None:
        t=t+solv(root.right,p,q)
    if t==2:
        ans=root
        print(ans.val)
    return t>0

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        solv(root,p,q)
        return ans