# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, dictt):
        if(root==None):
            return
        self.dfs(root.left,dictt)
        if(root.val in dictt.keys()):
            dictt[root.val]=dictt[root.val]+1
        else:
            dictt[root.val]=1
        self.dfs(root.right,dictt)
    
    def findMode(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        dictt={}
        result=[]
        self.dfs(root,dictt)
        print(dictt)
        maxx=dictt[root.val]
        for k in dictt:
            if(dictt[k]>maxx):
                maxx=dictt[k]
        for k in dictt:
            if(dictt[k]==maxx):
                result.append(k)
        return result
        