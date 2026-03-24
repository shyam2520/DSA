class Solution {
public:
    int getSplits(vector<int>& nums,int max_sum){
        int total=0,splits=0;
        for(auto& i:nums){
            if((i+total)>max_sum){
                splits++;
                total=i;
            }
            else total+=i;
        }
        return splits+1;
    }
    int splitArray(vector<int>& nums, int k) {
        // we are trying to minimize the 
        // the worse case sum would be entire sum of arry 
        // best case sum would be the large value of 
        // range of answers should be between this qualifies for splits 
        int total = 0,max_val=0;
        for(auto& i:nums){
            total+=i;
            max_val=max(max_val,i);
        } 
        int l=max_val,r=total;
        int res = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            // cout<<mid<<endl;
            if(getSplits(nums,mid)>k){
                l=mid+1;
            }
            else{
                res=mid;
                r=mid-1;
            }
        }
        return res;

    }
};