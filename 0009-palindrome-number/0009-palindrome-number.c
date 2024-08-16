bool isPalindrome(int x) {
        int temp;
        int a=x;
        long long b=0;
        if(x<0){
            return false;
        }
        while(a){
           temp=a%10;
           b=b*10+temp;
           a=a/10; 
        }
        if(x==b){
            return true;
        }else{
            return false;
        }
}