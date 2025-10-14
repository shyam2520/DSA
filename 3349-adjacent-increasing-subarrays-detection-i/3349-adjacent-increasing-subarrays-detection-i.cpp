class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int anc;
        int prev_end_idx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            anc=i;
            while(i+1<nums.size() && nums[i+1]>nums[i]) i++; 
            int sub_size = i-anc+1;
            if(sub_size>=k){
                if(sub_size>=k*2) return true;
                if(prev_end_idx!=INT_MIN && anc-prev_end_idx==1) return true;
                prev_end_idx = i;
            }
        }
        return false;
    }
};