class Solution {
public:
    int longestBalanced(vector<int>& nums) {
               int res =0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> even,odd;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2) odd[nums[j]]++;
                else even[nums[j]]++;
                if(odd.size()==even.size()) res=max(res,j-i+1);
            }
        }
        return res;
    }
};