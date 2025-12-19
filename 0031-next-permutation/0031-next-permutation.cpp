class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the idx , idx<idx+1 
        int r=nums.size()-2;
        while(r>=0 && nums[r]>=nums[r+1]) {
            r--;
        }

        if(r==-1) {
            sort(begin(nums),end(nums));
            return;
        }

        for(int i=nums.size()-1;i>r;i--){
            if(nums[i]>nums[r]){
                swap(nums[i],nums[r]);
                break;
            }
        }
        
        sort(begin(nums)+r+1,end(nums));


        // 2,3,5,4,1 ->
        // 1,2,3,4,5
        // 1,2,4,3,5

        // auto it = upper_bound(begin(nums),end(nums),nums[r]);
        // swap idx with its next greater value 
        
        // sort everything from idx+1
    }
};