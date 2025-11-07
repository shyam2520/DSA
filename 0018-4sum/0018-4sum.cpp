class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<vector<int>> res; 
        for(int i=0;i<n-3;i++){
            while(i>0 && i<n-3 && nums[i]==nums[i-1]) i++;
            for(int j=i+1;j<n-2;j++){
                while(j>i+1 && j<n-2 && nums[j]==nums[j-1]) j++;
                int k=j+1,l=n-1;
                while(k<l){
                    long long  sum = (long long)nums[i] +
                                    (long long)nums[j] +
                                    (long long)nums[k] +
                                    (long long)nums[l];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[k++],
                                    nums[l--]});
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum>target) l--;
                    else k++;
                }
            }
        }
        return res;
    }
};