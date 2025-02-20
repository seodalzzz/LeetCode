class Solution(object):
    def makeSmallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if(len(s)==1 or len(s)==0):
            return s
        result=""
        if(len(s)%2==1):
           pre=len(s)//2-1
           post=len(s)//2+1
           result=s[len(s)//2]
        else:
            pre=len(s)//2-1
            post=len(s)//2
        print(s[pre],result,s[post])
        while(post<len(s)):
            if(s[pre]!=s[post]):
                if(s[pre]<s[post]):
                    result=s[pre]+result+s[pre]
                else:
                    result=s[post]+result+s[post]
            else:
                result=s[pre]+result+s[post]
            pre=pre-1
            post=post+1
            print(pre, post)

        return result

        
        