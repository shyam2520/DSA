class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return ;
        int m=0,l=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==2){
                swap(nums[m],nums[h]);
                h--;
            }
            if(m<=h && nums[m]==1) m++;
            if(m<=h && nums[m]==0){
                swap(nums[m],nums[l]);
                m++;
                l++;
            }
        }
        
    }
};