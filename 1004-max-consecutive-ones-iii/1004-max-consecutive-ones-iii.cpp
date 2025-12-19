class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt_ones=0,cnt_zeros=0;
        int anc=0,res=0;;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1) cnt_ones++;
            else cnt_zeros++;
            while(anc<nums.size() && cnt_zeros>k){
                if(nums[anc]) cnt_ones--;
                else cnt_zeros--;
                anc++;
            }
            res=max(res,i-anc+1);
        }
        return res;
    }
};