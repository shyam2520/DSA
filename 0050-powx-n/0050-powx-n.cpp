class Solution {
public:
    double myPow(double x, int n) {
        bool powneg = n<0;
        bool neg_val = x<0;
        double res = powerVal(abs(x),abs((long)n));
        if(neg_val) neg_val=abs(n)&1;
        res=powneg?1/res:res;
        return neg_val?-res:res;
    }

    double powerVal(double x,long n){
        if(n==1) return x;
        if(n==0) return 1;
        if(n%2) return x*powerVal(x,(n-1));
        double ans = powerVal(x,n/2);
        return ans*ans;
    }
};