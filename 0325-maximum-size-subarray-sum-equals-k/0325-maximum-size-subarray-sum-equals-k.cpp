class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long,int> dict;
        long long sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            sum+=(long long)nums[i];
            if(sum==k) res=max(res,i+1);
            if(dict.count(sum-k)) res=max(res,i-dict[sum-k]);
            dict[sum]=dict.count(sum)?dict[sum]:i;
            // cout<<sum<<" "<<dict[sum]<<endl;
        }

        return res;
    }
};