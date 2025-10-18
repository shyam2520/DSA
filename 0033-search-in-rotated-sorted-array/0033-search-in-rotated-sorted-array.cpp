class Solution {
public:
    int binsearch(vector<int>& nums,int l,int r,int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;

    }
    int search(vector<int>& nums, int target) {
        int l=0,n=nums.size(),r=n-1;
        int rot=-1;
        if(nums.front()<nums.back() || nums.size()==1) return binsearch(nums,0,n-1,target);
        while(l<r)
        {
            int mid = l+(r-l)/2; 
            if(nums[mid]>nums[r]) {
                rot=mid;
                l=mid+1;
            }
            else r=mid; 
        }
        // if(rot==-1) return nums[l]>nums[l+1]
        return nums.front()<=target && nums[rot]>=target?binsearch(nums,0,rot,target):
                                                        binsearch(nums,rot+1,n-1,target);
    }
};