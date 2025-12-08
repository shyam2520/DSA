class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<(n));i++){
            int val=i;
            int cnt=0;
            vector<int> temp;
            while(val){
                if(val&1) temp.push_back(nums[cnt]);
                val>>=1;
                cnt++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};