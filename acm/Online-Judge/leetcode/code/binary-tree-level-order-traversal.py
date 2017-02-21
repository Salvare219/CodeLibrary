# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrderBottom(self, root):
        if root==None:
            return []
        q=[root]
        ans=[]
        while len(q)>0:
            t=[]
            v=[]
            for x in q:
                v.append(x.val)
                if x.left!=None:
                    t.append(x.left)
                if x.right!=None:
                    t.append(x.right)
            ans.append(v)
            q=t
        return ans[::-1]