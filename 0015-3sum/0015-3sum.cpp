class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            // int x=nums[i];
            while(i>0 && i<n-2 && nums[i]==nums[i-1]) i++;
            if(i==n-2) break;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(!sum){
                    res.push_back({nums[i],nums[j++],nums[k--]});
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                } 
                else if(sum>0) k--;
                else j++;
            }
        }

        return res;
    }
};