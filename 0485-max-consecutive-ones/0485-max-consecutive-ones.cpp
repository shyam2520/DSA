class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt =0,res =0;
        nums.push_back(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]) cnt++;
            else{
                res=max(res,cnt); 
                cnt=0;
                while(i<nums.size() && nums[i]==0) i++; 
                i--; 
            }
        }
        return res;
    }
};