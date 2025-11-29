class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int rev=0,copy=x;
        // regenerate x but in rev
        while(copy>0){
            int last_digit =copy%10;
            int rem=copy/10;
            copy=rem;
            rev=rev*10+last_digit;
        }

        return rev==x;
    }
};