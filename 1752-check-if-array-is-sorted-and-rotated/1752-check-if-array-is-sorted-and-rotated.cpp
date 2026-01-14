class Solution {
public:
    bool check(vector<int>& nums) {
        // find rotate pos
        int n = nums.size(), i=0;  
        for(i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                break;
            }
        }
        if(i==n) return true; 
        for(int j=i+1;(j%n)!=i;j++){
            int curr = j%n; 
            int prev = (j-1)%n;
            if(!(nums[curr]>=nums[prev])) return false;
        }
        return true;
    }
};