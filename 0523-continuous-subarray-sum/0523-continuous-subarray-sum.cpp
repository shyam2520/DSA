class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0,cntz=0;
        unordered_map<int,int> dict;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(!nums[i]){
                cntz++;
                if(cntz>1) return true;
            }
            else cntz=0;
            int rem = sum%k;
            if((sum%k)==0 && i>=1 ) return true;
            if(dict.count(sum%k)){
                if(i-dict[sum%k]>=2) return true;
            } 
            else dict[rem]=i;
        }
        return false;
    }
};