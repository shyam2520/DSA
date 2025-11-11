class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;

        int l=0,r=nums.size()-1; 
        if(nums[l]>nums[l+1]) return l;
        if(nums[r]>nums[r-1]) return r;
        l++,r--;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid; 
            if(nums[mid]>nums[mid-1]) l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
};