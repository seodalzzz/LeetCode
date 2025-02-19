# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def dfs(self, root, lst):
        if(root==None):
            return
        self.dfs(root.left,lst)
        lst.append(root.val)
        self.dfs(root.right,lst)

    def minDiffInBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        lst=[]
        self.dfs(root, lst)
        lst.sort()
        minn=lst[-1]-lst[0]
        for i in range(len(lst)-1):
            if(lst[i+1]-lst[i]<minn):
                minn=lst[i+1]-lst[i]
        return minn
        