class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(auto& i:nums){
            if(nums[abs(i)]<0) return abs(i);
            nums[abs(i)]=-nums[abs(i)];
        }
        return -1;
    }
};