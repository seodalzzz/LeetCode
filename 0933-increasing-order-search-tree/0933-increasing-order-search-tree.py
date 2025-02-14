# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, dfslist):
        if(root==None):
            return
        self.dfs(root.left, dfslist)
        dfslist.append(root.val)
        self.dfs(root.right,dfslist)
        return dfslist

    def increasingBST(self,root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        dfslist=[0]
        self.dfs(root, dfslist)
        dfslist.sort()
        dfslist.pop(0)
        root.left=None
        root.right=None
        curr=root
        for i in dfslist:
            curr.right=TreeNode(val=i)
            curr=curr.right
        
        return root.right


    