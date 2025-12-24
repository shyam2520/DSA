class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int,int> dict;
        for(int i=0;i<n;i++){
            dict[nums[i]-i]++;
        }

        long long total =0;
        for(auto& i:dict){
            total+=(i.second *(i.second-1))/2;
        }
        return (n*(n-1))/2  - total;
    }
};