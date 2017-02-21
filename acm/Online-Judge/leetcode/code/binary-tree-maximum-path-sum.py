# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    ans=0
    def dfs(self,root):
        if root==None:
            return 0
        x,y=self.dfs(root.left),self.dfs(root.right)
        self.ans=max(self.ans,x+y+root.val)
        return max(0,max(x,y)+root.val)
    def maxPathSum(self, root):
        self.ans=-100000000
        self.dfs(root)
        return self.ans