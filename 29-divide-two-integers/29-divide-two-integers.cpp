class Solution {
public:
    int divide(long int dividend, long int divisor) {
        long int res=0;
        bool sign=false;
        // if(divisor<0) cout<<"true"<<endl;
        // if(dividend>0) cout<<"true";
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) sign=true;
        // cout<<sign<<endl;
        dividend=abs(dividend);
        divisor=abs(divisor);
        // cout<<dividend<<" "<<divisor<<" "<<sign<<endl;

        if(divisor==1) return sign? -dividend<INT_MIN?INT_MIN:-dividend:dividend>INT_MAX?INT_MAX:dividend;
        if(dividend==divisor) return sign?-1:1;
        while(dividend>=0)
       {
            res++;
            dividend-=divisor;
        }
        // cout<<res<<endl;
        return sign? -1* (res-1):res-1;
    }
};