class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),pre_even=0;
        vector<int> prefix(n,0);
        for(int i=0;i<nums.size();i++){
            prefix[i]=pre_even;
            if(nums[i]&1) pre_even=0;
            else pre_even++;
        }
        int odd_count=0,res=0,anc=0;
        for(int i=0;i<n;i++){
            odd_count+=nums[i]&1;
            while(anc<i && odd_count>k){
                odd_count-=nums[anc]&1;
                anc++;
            }
            if(odd_count==k){
                while(anc<i && (nums[anc]&1)==0) anc++;
                res+=(prefix[anc]+1);
            }
        }
        return res;
    }
};