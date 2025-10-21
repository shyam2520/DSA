class Solution {
public:
    bool check(vector<int>& nums) {

        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[i-1]) continue;
            else{
                int peak = nums[i-1]; 

                while(i+1<nums.size() && nums[i]<=nums[i+1]) i++; 
                if(i==nums.size()-1 && nums[i]<=peak && nums.front()>=nums[i]) return true;
                else return false;
            }
        }

        return true;
    }
};