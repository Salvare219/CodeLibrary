# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:
    # @param root, a binary search tree's root node
    path=[]
    
    def dfs(self,root):
        if root==None:
            return 
        self.dfs(root.left)
        self.path.append(root.val)
        self.dfs(root.right)
    
    def __init__(self, root):
        self.path=[]
        self.dfs(root)
        self.path=self.path[::-1]

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return len(self.path)>0

    # @return an integer, the next smallest number
    def next(self):
        t=self.path[len(self.path)-1]
        self.path.pop()
        return t

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())