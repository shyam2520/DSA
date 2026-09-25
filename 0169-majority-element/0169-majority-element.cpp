class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,curr=-1;
        for(auto& i:nums){
            if(!cnt){
                curr=i;
                cnt=1;
            }
            else if(i==curr){
                cnt++;
            }
            else cnt--;
        }
        return curr;
    }
};