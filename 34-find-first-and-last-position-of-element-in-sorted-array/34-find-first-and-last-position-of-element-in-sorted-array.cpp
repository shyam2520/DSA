class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        int l=lsearch(nums,target);
        // cout<<l<<endl;
        int r=rsearch(nums,target);
        return {l,r};
    }
    
    int lsearch (vector<int>& nums,int target)
    {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>=target) r=mid;
            else l=mid+1;
        }
        
        return nums[l]==target?l:-1;
    }
    
    int rsearch (vector<int>& nums,int target)
    {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]<=target) l=mid+1;
            else r=mid;
        }
        
        return nums[l]==target?l:(l>0 && nums[l-1]==target)?l-1:-1;
    }
};