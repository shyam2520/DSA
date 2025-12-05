class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=0;
        if(n<0) return false;
        while(n){
            cnt+=n&1;
            n>>=1;
            if(cnt>1) return false;
        }
        return cnt==1;
    }
};