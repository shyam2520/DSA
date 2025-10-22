class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]) continue; 
            int idx=i;
            while(i<nums.size() && nums[i] ) i++; 
            res=max(res,i-idx);
        }
        return res;
    }
};