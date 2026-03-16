class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long digits = 0, cnt=0;
        long long cpy = n ;
        while(cpy){
            digits++;
            cpy/=10;
        }
        int commas = (digits-1)/3; 
        long long max_val = n,res=0;
        for(;commas>0;commas--){
            long long min_val = pow(10,3*commas);
            res+=commas*(max_val-min_val+1);
            max_val = min_val-1;
        }
        return res;   
    }
};

