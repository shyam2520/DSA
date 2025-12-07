class Solution {
public:
    int minBitFlips(int start, int goal) {
        int set_missing_bits = start^goal;
        int cnt=0;
        while(set_missing_bits){
            cnt+=set_missing_bits&1;
            set_missing_bits>>=1;
        }
        return cnt;
    }
};