class Solution(object):
    def is_palindrome(self, s):
        return s==s[::-1]
    def largestPalindromic(self, num):
        """
        :type num: str
        :rtype: str
        """
        dictt={}
        for i in range(len(num)):
            if(num[i] in dictt.keys()):
                dictt[num[i]]=dictt[num[i]]+1
            else:
                dictt[num[i]]=1
        lst2=[]
        lst1=[]
        for kk in dictt.keys():
            if(dictt[kk]>=2):
                if(dictt[kk]>=3 and dictt[kk]%2!=0):
                    lst1.append(kk)
                    dictt[kk]=dictt[kk]-1
                lst2.append(kk)
            else:
                lst1.append(kk)
        print("lst1 : ", lst1)
        print("lst2: ", lst2)
        lst1.sort()
        lst2.sort()
        print("lst1 : ", lst1)
        print("lst2: ", lst2)
        if(len(lst1)==0):
            lst1.append(-1)
        if(len(lst2)==0):
            lst2.append(-1)

        cand=max(lst1)
        max2=max(lst2)
        min2=min(lst2)
        print("cand: ",cand)
        print("max2: ",max2)
        print("min2: ",min2)
        result=""
        # if(min2<=cand):
        if(cand>=0):
            result=cand
        else:
            result=""

        for i in lst2:
            if(i>=0):
                result=i*(dictt[i]//2)+result+i*(dictt[i]//2)  
        
        print("result :", result)
        while(result[0]==u'0'):
            result=result[1:-1]
            if(len(result)==0):
                return "0"
        return result

        #keys 중에 2개 이상인 애들 골라내서 sort
            #max가 0이면 ""이거나 cand만 return
        #1개인 애들 중에 제일 큰애로 가운데 넣을 후보 정하기
        #min(2개 이상)<cand 이면 cand 를 중심으로 붙이기
        #아니면 cand없이 그냥 붙이기
        #작은애부터 양쪽에


        