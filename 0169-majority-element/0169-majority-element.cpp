class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums.front(),cnt=1;
        for(int i=1;i<nums.size();i++){
            if(!cnt) {
                val=nums[i];
                cnt=1;
            }
            else if(nums[i]==val) cnt++;
            else cnt--;
        }
        return val;
    }
};