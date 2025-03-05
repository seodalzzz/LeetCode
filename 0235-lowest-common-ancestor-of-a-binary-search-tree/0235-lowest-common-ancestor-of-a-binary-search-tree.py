class Solution(object):
    def dfs(self, root, p, q):
        if root is None:
            return False, False, None
        
        lp, lq, lca_left = self.dfs(root.left, p, q)
        rp, rq, lca_right = self.dfs(root.right, p, q)

        if lca_left:  # 왼쪽 서브트리에서 LCA를 찾은 경우
            return True, True, lca_left
        if lca_right:  # 오른쪽 서브트리에서 LCA를 찾은 경우
            return True, True, lca_right

        found_p = lp or rp or root == p
        found_q = lq or rq or root == q

        if found_p and found_q:
            return True, True, root  # 현재 노드가 LCA

        return found_p, found_q, None  # 아직 LCA를 찾지 못한 경우

    def lowestCommonAncestor(self, root, p, q):
        _, _, lca = self.dfs(root, p, q)
        return lca
