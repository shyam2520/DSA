class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1) return nums[0]==target?0:-1;
        int mid, l = 0, r = nums.size() - 1;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }
        int pivot = l,n=nums.size();
        l = 0, r = nums.size() - 1;
        // cout<<pivot<<endl;
        while(l<=r){
            mid=l+(r-l)/2;
            int realidx = (pivot+mid)%n;
            // cout<<realidx<<endl;
            if(nums[realidx]==target) return realidx;
            if(nums[realidx]>target) r=mid-1;
            else l=mid+1;
        }
        return nums[l]==target?l:-1;
    }
};