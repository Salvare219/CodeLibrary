# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def solv(self,root,dep):
        if root==None:
            return 0
        t=root.left
        cnt=1
        while t!=None:
            t=t.right
            cnt+=1
        if cnt==dep:
            return (1<<(dep-1))+self.solv(root.right,dep-1)
        else:
            return self.solv(root.left,dep-1)+(1<<(dep-2))
        
    def countNodes(self, root):
        dep=0
        t=root
        while t!=None:
            dep+=1
            t=t.left
        return self.solv(root,dep)