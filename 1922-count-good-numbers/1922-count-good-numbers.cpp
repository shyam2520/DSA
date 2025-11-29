class Solution {
public:
    long long mod=1e9+7;
    long long powMod(int val, long long pow){
        if(pow==0) return 1;
        if(pow%2) return (val * powMod(val,pow-1)%mod)%mod;
        long long res = (powMod(val,pow/2))%mod;
        return (res * res)%mod;
    }


    int countGoodNumbers(long long n) {
        long long evenIndices=n%2?n/2 + 1 :n/2;
        long long oddIndices=n/2;
        return (powMod(5,evenIndices) * powMod(4,oddIndices)) %mod;
    }
};