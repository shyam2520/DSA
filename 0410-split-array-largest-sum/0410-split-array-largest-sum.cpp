class Solution {
public:
    int get_subarray(vector<int>& nums,int max_sum){
        int total = 0,sub_array=0;
        for(int i=0;i<nums.size();i++){
            if(total+nums[i]>max_sum){
                sub_array++;
                total=nums[i];
            }
            else total+=nums[i];
        }
        return sub_array;
    }

    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0,ans=-1,mid;
        for(auto& i:nums){
            l=max(i,l); 
            r+=i;
        }
        nums.push_back(r);
        while(l<=r){
            mid=l+(r-l)/2;
            if(get_subarray(nums,mid)>k) l=mid+1; 
            else {
                ans=mid;
                r=mid-1;
            }
        }

        return ans;
    }
};