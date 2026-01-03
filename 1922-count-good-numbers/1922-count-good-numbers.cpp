class Solution {
public:

    long long mod = 1e9+7;
    int countGoodNumbers(long long n) {
        // n=3 
        // 022
        // 1-9 -> 5(e), 4(p)
        // _,_,_
        // power(5,100) -> res = (a*b)%mod -> (a%mod * b%mod)%mod
        // 1. check for even len or odd len -> if even= n/2 , odd n/2+1 , 4 ->n/2 
        // 2. pow(x,a)-> x^n = x^(n/2) * x^(n/2)
        long long pow_ev=0,pow_od=0;
        if(n%2){
            pow_ev = n/2  + 1;
            pow_od = n/2;
        }
        else{
            pow_ev = n/2;
            pow_od = n/2;
        }
        long long even = get_power(5,pow_ev)%mod;
        long long odd = get_power(4,pow_od)%mod;
        return (even*odd)%mod;
    }

    long long get_power(long long x,long long pow){
        if(pow==0) return (long long)1;
        if(pow==1) return (long long)x;
        if(pow%2){
            long long ans = get_power(x,pow-1)%mod;
            return ((x%mod) * ans)%mod;
        }
        else{
            long long ans = get_power(x,pow/2)%mod;
            return (ans*ans)%mod;
        }
    }
};