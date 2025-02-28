# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, k, result):
        if(root==None):
            return 0
        self.dfs(root.left,k,result)
        result.append(root.val)
        self.dfs(root.right, k, result)
        

    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        result=[]
        self.dfs(root, k, result)
        return result[k-1]
        