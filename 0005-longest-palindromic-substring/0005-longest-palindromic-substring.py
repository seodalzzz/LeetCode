class Solution(object):
    def is_palindrome(self, s):
        return s==s[::-1]

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        maxlen=0
        result=""
        #시작 인덱스
        if(len(s)==1):
            return s
        for i in range(len(s)):
            for j in range(i+maxlen,len(s)+1):
                if(self.is_palindrome(s[i:j])):
                    if(maxlen<len(s[i:j])):
                        maxlen=len(s[i:j])
                        result=s[i:j]
        return result



        