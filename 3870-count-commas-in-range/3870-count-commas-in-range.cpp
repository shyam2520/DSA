class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int digits = 0, cnt=0;
        int cpy = n ;
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