class Solution {
public:
    bool binsearch(vector<int>& nums,int l,int r,int& target){
        int mid; 
        while(l<=r){
            mid=l+(r-l)/2; 
            if(nums[mid]==target) return true;
            if(nums[mid]>target) r=mid-1; 
            else l=mid+1; 
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1; 
        if(nums.front()<nums.back() || nums.size()==1) return binsearch(nums,l,r,target);
        int rot=-1;
        while(l<=r){
            int mid=l+(r-l)/2; 
            if(nums[mid]>nums.back()) {
                rot=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        // cout<<rot<<endl;
        if(rot==-1) {
            // its because all the mid values <numbs.back() shoudl be sorted or
            // the value should be == nums.back() 
            for(int i=0;i<nums.size();i++) if(nums[i]==target) return true;

        }        
        if(target<=nums.back()) return binsearch(nums,rot+1,nums.size()-1,target);
        return binsearch(nums,0,rot,target);
    }
};