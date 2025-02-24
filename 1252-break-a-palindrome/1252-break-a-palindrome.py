class Solution(object):

    def is_palindrome(self,s):
        return s==s[::-1]
    def breakPalindrome(self, palindrome):
        """
        :type palindrome: str
        :rtype: str
        """
        if(len(palindrome)==1):
            return ""
        for i in range(len(palindrome)):
            if(palindrome[i]=='a'):
                continue
            else:
                result=palindrome[:i]+"a"+palindrome[i+1:]
                if(self.is_palindrome(result)):
                    result=palindrome
                    result=palindrome[:-1]+"b"
                return result
        
        return palindrome[:-1]+"b"