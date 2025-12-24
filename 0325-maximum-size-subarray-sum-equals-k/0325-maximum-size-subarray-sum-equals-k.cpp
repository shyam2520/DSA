class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long,long> dict;
        long sum=0,res=0;
        dict[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(dict.find(sum-k)!=dict.end()){
                res=max(res,i-dict[sum-k]);
            }
            if(dict.find(sum)==dict.end()){
                dict[sum]=i;
            } 
        }
        return res;
    }
};