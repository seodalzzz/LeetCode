class Solution:
    def isPalindrome(self, x: int) -> bool:

        palind=[]
        if(x<0):
            return False
        while(x!=0):
            palind.append(x%10)
            x=int(x/10)

        if(palind==palind[::-1]):
            return True
        else:
            return False
        