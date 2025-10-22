class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_cnt=0,anc=0;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]) zero_cnt++; 
            else nums[anc++]=nums[i];
        }
        int idx=nums.size()-1;
        while(zero_cnt-->0) nums[idx--]=0;
    }
};