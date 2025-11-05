class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> dict; 
        int sum =0,cnt=0; 
        for(auto& i:nums){
            sum+=i;
            if(sum==k) cnt++; 
            cnt+=dict[sum-k];
            dict[sum]++;
        }
        return cnt;
    }
};