class Solution {
public:
    int divide(int dividend, int divisor) {
        long lds=abs((long)divisor);
        long ldiv=abs((long)dividend);
        bool neg=false;
        if((divisor<0 && dividend>0) || (divisor>0 && dividend<0)) neg=true;
        long ans=0;
        while(ldiv>=lds)
        {
            int cnt=0;
            while(ldiv>=(lds*pow(2,cnt+1))) cnt++;
            ans+=pow(2,cnt);
            ldiv-=lds*pow(2,cnt);
        }   
        ans = neg?-ans:ans ;
        return ans<INT_MIN?INT_MIN:ans>INT_MAX?INT_MAX:ans;
    }
};