class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long max_val=0,second_max=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
            if(nums[i]>=max_val){
                second_max=max_val;
                max_val=nums[i];
            }
            if(nums[i]>=second_max && nums[i]<max_val) second_max=nums[i];
        } 
        // sort(begin(nums),end(nums));
        

    
        // cout<<nums.back()<<" "<<second_max<<endl;
        long long res = (long long)max_val*(long long)second_max * 100000;
        return res;
            
    }
};