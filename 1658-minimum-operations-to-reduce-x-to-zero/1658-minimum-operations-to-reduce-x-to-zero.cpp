class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(auto& i:nums) total+=i;
        total-=x;
        if(!total) return nums.size();
        int i=0;
        int sum=0,res=0;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(i<=j && sum>total) 
                sum-=nums[i++];
            if(sum==total) res=max(res,j-i+1); 
        }
        return res==0?-1:nums.size()-res;
    }
};