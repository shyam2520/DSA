class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int anc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                nums[anc++]=nums[i];
            } 
        }
        for(anc;anc<nums.size();anc++) nums[anc]=0;
    }
};