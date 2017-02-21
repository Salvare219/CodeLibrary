# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

            
class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {integer[][]}
    path=[]
    ans=[]
    def dfs(self,root,s,tot):
        if root==None:
            return 
        self.path.append(root.val)
        tot+=root.val
        if root.left==None and root.right==None:
            if s==tot:
                self.ans.append(self.path[::])
        self.dfs(root.left,s,tot)
        self.dfs(root.right,s,tot)
        self.path.pop()
    def pathSum(self, root, sum):
        self.ans=[]
        self.path=[]
        self.dfs(root,sum,0)
        return self.ans
        
        
        