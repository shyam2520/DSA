class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        // while(i<n && nums[i]<0) i++;
        // while(j<n && nums[j]>=0) j++;
        vector<int> res;
        while(i<n && j<n){
            while(i<n && nums[i]<0) i++;
            res.push_back(nums[i++]);
            while(j<n && nums[j]>=0) j++;
            res.push_back(nums[j++]);
        }

        while(i<n && nums[i]>=0) res.push_back(nums[i++]);
        while(j<n && nums[j]<0) res.push_back(nums[j++]);
        return res;
    }
};