class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,lpos=nums.size();
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(nums[mid]<target) l=mid+1;
            else{
                lpos=mid;
                r=mid-1;
            }
        }
        if(lpos==nums.size() || nums[lpos]!=target) return {-1,-1};

        l=lpos;r=nums.size()-1;int rpos=nums.size();
        while(l<=r){
            int mid = l+(r-l)/2; 
            if(nums[mid]<=target){
                rpos=mid;
                l=mid+1;
            } 
            else r=mid-1;
        }

        return {lpos,rpos};
    }
};