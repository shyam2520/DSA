class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> val(begin(nums),end(nums));
        nums=vector<int>(begin(val),end(val));
        int start=0;
        int res=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-1!=nums[i-1])
            {
                res=max(res,i-start);
                start=i;
            }
        }
        return max(res,(int)(nums.size()-start));
    }
};