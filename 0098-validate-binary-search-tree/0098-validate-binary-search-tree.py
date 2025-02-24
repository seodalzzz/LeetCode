# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def dfs(self, root):
        if(root==None):
            return True , 99999999999,-99999999999
        now_result=True
        left_result=True
        right_result=True
        left_result, left_min1, right_max1=self.dfs(root.left)
        right_result, left_min2, right_max2=self.dfs(root.right)
        if(root.left!=None):
            now_result=root.left.val<root.val
            if(right_max1>=root.val):
                left_result=False
        if(root.right!=None):
            now_result=now_result and root.right.val>root.val
            if(left_min2<=root.val):
                right_result=False
        print(root.val,min(left_min1,left_min2,root.val),max(right_max1, right_max2, root.val))
        return left_result and right_result and now_result, min(left_min1,left_min2,root.val), max(right_max1, right_max2, root.val)
        

    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        result, re_min, re_max=self.dfs(root)
        return result 
        