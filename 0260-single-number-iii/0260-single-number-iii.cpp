class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long res =0;
        for(auto& i:nums) res^=i;
        long long rsb = (res&res-1) ^ res;
        // int rsb=res;
        // while(rsb&1==0) rsb=rsb>>1;
        // rsb = 1<<rsb;
        int b1=0,b2=0;
        for(auto& i:nums){
            if(i&rsb) b1^=i;
            else b2^=i;
        }
        return {b1,b2};
    }
};