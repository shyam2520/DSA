class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,res;
        for(int i=0;i<nums.size();i++){
            if(!cnt){
                cnt++; 
                res=nums[i];
            }
            else{
                if(res==nums[i]) cnt++;
                else cnt--;
            }
        }
        return res;
    }
};