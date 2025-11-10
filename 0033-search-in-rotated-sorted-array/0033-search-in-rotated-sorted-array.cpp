class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if(nums.size()==1) return nums.back()==target?0:-1;
        int l=0,r=nums.size()-1,ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>nums.back()){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        // ans=nums[l]>nums.back()?l:ans;
        if(ans==-1) {
            l=0;r=nums.size()-1;
        }
        else{
            if(target<=nums.back()) {
                l=ans+1;
                r=nums.size()-1;
            }
            else{
                l=0;
                r=ans;
            }
        }

        while(l<=r){
            int mid =l+(r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) r=mid-1;
            else l=mid+1;
        }
        return -1;

    }
};