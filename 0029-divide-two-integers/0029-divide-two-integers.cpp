class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ds=abs((long long)divisor);
        long long div=abs((long long)dividend);
        bool neg = false;
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) neg=true;
        if(!dividend || divisor==1) return dividend; 
        long long cnt=0;
        while(div-ds>=0){
            cnt++;
            div-=ds;
        }
        cnt=neg?-cnt:cnt;
        return cnt>INT_MAX?INT_MAX:cnt<INT_MIN?INT_MIN:cnt;
    }
};