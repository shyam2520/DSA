class Solution {
public: 
    // unordered_map<double,double> dp;
    double calPower(double x,int pow){
        // cout<<x<<" "<<pow<<endl;
        // if(dp.count(pow)) return dp[pow];
        if(pow==0) return 1.0;
        if(pow==1) return x;
        if(pow%2) return x*calPower(x,pow-1);
        double res=calPower(x,pow/2);
        return res*res;
        // if((pow%2)!=0) return dp[pow]=calPower(x,pow/2) * calPower(x,(pow/2)+1);
        // return dp[pow]=calPower(x,pow/2)*calPower(x,pow/2);
    }

    double myPow(double x, int n) {
        double res;    
        if(n==INT_MIN){
            res=calPower(x,1)*calPower(x,INT_MAX);
        }
        else res=calPower(x,abs(n));
        return n>0?res:1/res;
    }
};