class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        dict[0]=1;
        int prefix_sum=0,n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            prefix_sum+=nums[i];
            if(dict.count(prefix_sum-k)){
                ans+=dict[prefix_sum-k];
            }
            dict[prefix_sum]++;
        }
        return ans;
    }
};