class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n = nums.size(); 
        for(i=n-2;i>=0;i--) if(nums[i]<nums[i+1]) break;
        if(i<0){
            reverse(begin(nums),end(nums));
            return; 
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[i]) {
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(begin(nums)+i+1,end(nums));
    }
};