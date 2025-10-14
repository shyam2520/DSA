class Solution {
public:
    int lower_bound(vector<int>& nums,int target){
        int l=0,r=nums.size()-1; 
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(nums[mid]<target) l=mid+1; 
            else r=mid-1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lpos = lower_bound(nums,target); 
        int rpos = lower_bound(nums,target+1)-1;
        vector<int> res;
        res.push_back(0<=lpos && lpos<nums.size() && nums[lpos]==target?lpos:-1);
        res.push_back(0<=rpos && rpos<nums.size() && nums[rpos]==target?rpos:-1);
        return res;
    }
};