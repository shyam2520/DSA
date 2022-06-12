class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0;
        vector<int> dict(10001,0);
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(dict[nums[i]]>0)
            {
                while(nums[l]!=nums[i])
                {
                    dict[nums[l]]--;
                    sum-=nums[l++];
                }
                l++;
            }
            else
            {
                sum+=nums[i];
                dict[nums[i]]++;
            }
            // cout<<sum<<endl;
            res=max(res,sum);
            
        }
        return res;
    }
};