 class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,ans=-1; 
        while(l<=r){
            int mid = l+(r-l)/2;
            cout<<mid<<endl;
            int left_val=mid-1<0?INT_MIN:nums[mid-1];
            int right_val=mid+1==nums.size()?INT_MAX:nums[mid+1];
            if(nums[mid]!=left_val && nums[mid]!=right_val) return nums[mid];
            if(nums[mid]==right_val){
                int size=r-(mid+1);
                if(size%2==0) r=mid-1;
                else l=mid+2;
            }
            else{
                int size = mid-1;
                if(size%2) r=mid-2;
                else l=mid+1;
            }
        }
        return -1;
    }
};