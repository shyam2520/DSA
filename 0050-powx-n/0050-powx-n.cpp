class Solution {
public:
    double myPow(double x, long n) {
        bool powneg = n<0;
        bool neg_val = x<0;
        if(abs(x)==1) return n%2==0?1:neg_val?-1:1;
        if(neg_val) neg_val=abs(n)&1;
        double res=1; 
        x=abs(x);
        n=abs(n);
        while(n>0 && res<=100000){
            if(n&1==0)
            {
                x=(x*x);
                n>>=1;
            }
            else{
                res*=x;
                n=n-1;
            }
        }
        res=powneg?1/res:res;
        return neg_val?-res:res;
    }

    // double powerVal(double x,long n){
    //     if(n==1) return x;
    //     if(n==0) return 1;
    //     if(n%2) return x*powerVal(x,(n-1));
    //     double ans = powerVal(x,n>>1);
    //     return ans*ans;
    // }
};