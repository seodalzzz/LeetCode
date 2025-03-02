class Solution(object):
    def is_palindrome(self, s):
        return s==s[::-1]


    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        dictt={}
        for i in range(len(s)):
            if(s[i] in dictt.keys()):
                dictt[s[i]]=dictt[s[i]]+1
            else:
                dictt[s[i]]=1


        #1개인거 아무거나 고르기
        #2개이상->홀수개면 짝수개로 바꾸기
        #짝수개인거 갯수 다 더하기
        result=0
        flag=0
        for k in dictt.keys():
            if(dictt[k]%2!=0):
                flag=1
                dictt[k]=dictt[k]-1
            result=result+dictt[k]
        result=result+flag
        return result
        