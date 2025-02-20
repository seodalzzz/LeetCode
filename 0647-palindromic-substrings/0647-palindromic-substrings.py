class Solution(object):
    def is_palindrome(self,s):
        return s==s[::-1]
    
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        result=0
        for i in range(len(s)): # i: 시작 인덱스
            for j in range(i+1,len(s)+1): #j : 끝
                if(self.is_palindrome(s[i:j])):
                    result=result+1

        return result
