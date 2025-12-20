class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> dict;
        int sum=0,res=0;
        dict[0]=1;
        for(auto& i:nums){
            sum+=i; // prefixsum 
            if(dict.count(sum-goal)){
                res+=dict[sum-goal];
            }
            dict[sum]++;
        }
        return res;
    }
};