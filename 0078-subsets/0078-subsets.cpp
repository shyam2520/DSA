class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        cout<<(1<<n);
        int idx,cnt;
        vector<vector<int>> res;
        for(int i=0;i<(1<<n);i++){
            idx=i;
            cnt=0;
            vector<int> temp;
            while(idx){
                if(idx&1){
                    temp.push_back(nums[cnt]);
                }
                cnt++;
                idx>>=1;
            }
            res.push_back(temp);
        }
        return res;
    }
};