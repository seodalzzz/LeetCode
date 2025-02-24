class Solution(object):
    def is_palindorme(self, s):
        return s==s[::-1]

    def represent_base(self, n, b):
        num=n
        mod=str()
        while(num!=0):
            mod=mod+str(num%b)
            num=num//b
        return self.is_palindorme(mod)

    def isStrictlyPalindromic(self, n):
        """
        :type n: int
        :rtype: bool
        """
        for i in range(2,n-1):
            if(not self.represent_base(n,i)):
                return False
        return True
        