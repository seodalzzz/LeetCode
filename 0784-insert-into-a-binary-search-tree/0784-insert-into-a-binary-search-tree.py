# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        prev=root
        curr=root
        if(root==None):
            root=TreeNode(val=val)
            return root
        while(curr!=None):
            prev=curr
            if(curr.val<val):
                curr=curr.right
            else:
                curr=curr.left
        if(prev.val<val):
            prev.right=TreeNode(val=val)
        else:
            prev.left=TreeNode(val=val)
        return root
