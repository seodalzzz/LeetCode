class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        is_palindrome = [[False] * len(s) for i in range(len(s))]
        for i in reversed(range(len(s))):
            for j in range(i, len(s)):
                is_palindrome[i][j] = s[i] == s[j] and ((j - i < 2) or is_palindrome[i + 1][j - 1])

        sub_partition = [[] for _ in range(len(s))]
        for i in reversed(range(len(s))):
            for j in range(i, len(s)):
                if is_palindrome[i][j]:
                    if j + 1 < len(s):
                        for p in sub_partition[j + 1]:
                            sub_partition[i].append([s[i:j + 1]] + p)
                    else:
                        sub_partition[i].append([s[i:j + 1]])

        return sub_partition[0]