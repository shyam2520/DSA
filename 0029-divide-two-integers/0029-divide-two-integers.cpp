class Solution {
public:
    int divide(long long  dividend, long long  divisor) {
        bool sign = false; 
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) sign=true;
        dividend = abs(dividend);
        divisor = abs(divisor); 
        long long  ans=0;
        while(dividend>=divisor){
            long long  n=0;
            while(dividend>(pow(2,n+1)*divisor)){
                n++;
            }
            dividend-=(pow(2,n)*divisor);            
            ans+=pow(2,n);
            if(ans>INT_MAX) break;
        }
        if(sign){
            ans = -ans;
            return ans<INT_MIN?INT_MIN:ans;
        }
        return ans>INT_MAX?INT_MAX:ans;
    }
};