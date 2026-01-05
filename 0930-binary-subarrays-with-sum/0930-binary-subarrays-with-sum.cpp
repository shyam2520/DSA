class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),sum=0;
        unordered_map<int,int> dict;
        dict[0]=1;
        int res = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(dict.count(sum-goal)){
                res+=dict[sum-goal];
            }
            dict[sum]++;
        }
        return res;
    }
};