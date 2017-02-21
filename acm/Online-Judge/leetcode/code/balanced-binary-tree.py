# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def hasPathSum(self, root, sum):
        if root==None:
            return False
        sum-=root.val
        if root.left==None and root.right==None:
            return sum==0
        if root.left==None:
            return self.hasPathSum(root.right,sum)
        if root.right==None:
            return self.hasPathSum(root.left,sum)
        return self.hasPathSum(root.right,sum)|self.hasPathSum(root.left,sum)