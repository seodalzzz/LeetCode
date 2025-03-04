# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def dfs(self, root,):
        if(root==None):
            return 999999999999,-9999999999999, True
        lmin,lmax,lresult=self.dfs(root.left)
        rmin,rmax,rresult=self.dfs(root.right)
        minn=min(lmin,rmin)
        maxx=max(lmax,rmax)
        result=lmax<root.val and rmin>root.val and lresult and rresult
        return  min(minn,root.val), max(maxx,root.val), result


    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        # left->min,max 리턴받기
        # right->min,max 리턴받기
        # left->max > root.val 이거나 right -> min < root.val 이면 invalid
        minn,maxx,result=self.dfs(root)
        return result

        