class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<2) return true;
        
        int count=0;
        for(int i=1;i<nums.size()&& count<2;i++)
        {
            if(nums[i]<nums[i-1])
            {
                count++;
                if(i>1)
                {
                    if(nums[i]<nums[i-2]) nums[i]=nums[i-1];
                    else nums[i-1]=nums[i];
                }
            }
        }
        return count<2;
    }
};