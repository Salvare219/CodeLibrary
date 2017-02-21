# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def ok(self,x,y):
        if x==None and y==None:
            return True
        if x==None or y==None:
            return False
        if x.val!=y.val:
            return False
        return self.ok(x.left,y.right)&self.ok(x.right,y.left)
    def isSymmetric(self, root):
        if root==None:
            return True
        return self.ok(root.left,root.right)