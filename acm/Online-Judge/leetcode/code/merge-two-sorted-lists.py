# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def Balanced(self, root):
        if root==None:
            return 0
        t1=self.Balanced(root.left)
        t2=self.Balanced(root.right)
        if t1<0 or t2<0:
            return -1
        if abs(t1-t2)>1:
            return -1
        return max(t1,t2)+1
    def isBalanced(self, root):
        return self.Balanced(root)!=-1