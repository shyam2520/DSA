class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums,0,nums.size()-1);
        return nums;
    }

    void mergesort(vector<int>& nums,int l,int r){
        if(l>=r) return; 
        int mid=l+(r-l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        vector<int>res =merge(nums,l,mid,r);
        for(int i=0;i<res.size();i++) nums[l+i]=res[i];
    }

    vector<int> merge(vector<int>& nums,int l,int mid,int r){
        vector<int> res;
        int i=l,j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]) res.push_back(nums[i++]);
            else res.push_back(nums[j++]);
        }

        while(i<=mid) res.push_back(nums[i++]);
        while(j<=r) res.push_back(nums[j++]);
        return res;
    }

};