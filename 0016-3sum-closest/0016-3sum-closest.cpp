class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int diff=INT_MAX,res=-1;
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum = nums[l]+nums[r]+nums[i];
                if(sum==target) return sum;
                if(abs(target-sum)<diff){
                    res=sum;
                    diff=abs(target-sum);
                } 
                if(sum>target) r--;
                else l++;
            }
        }
        return res;
    }
};