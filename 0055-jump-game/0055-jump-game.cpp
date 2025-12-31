class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxidx=0;
        for(int i=0;i<nums.size();i++){
            if(i<=maxidx){
                if(i==nums.size()-1) return true;
                maxidx=max(maxidx,nums[i]+i);
            }
            else return false;
        }
        return true;
    }
};