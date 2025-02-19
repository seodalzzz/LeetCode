# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, low, high,lst):
        if(root==None):
            return
        self.dfs(root.left, low, high,lst)
        if root.val>=low and root.val<=high:
            lst.append(root.val)
        self.dfs(root.right, low, high, lst)


    def rangeSumBST(self, root, low, high):
        """
        :type root: Optional[TreeNode]
        :type low: int
        :type high: int
        :rtype: int
        """
        lst=[]
        self.dfs(root, low, high, lst)
        return sum(lst)