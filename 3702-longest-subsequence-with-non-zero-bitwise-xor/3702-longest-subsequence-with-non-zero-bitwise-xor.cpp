class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        if(nums.size()==1 && nums[0]==0) return 0;
        int xor_sum=nums[0]; 
        for(int i=1;i<nums.size();i++) xor_sum^=nums[i];
        // cout<<xor_sum<<endl;
        return xor_sum==0?xor_sum^nums[nums.size()-1] || nums[0]^xor_sum?nums.size()-1:0:nums.size();
    }
};