class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixsum(n,0);
        vector<int> subcnt(n,0);
        for(int i=0;i<n;i++){
            prefixsum[i]+=nums[i];
            subcnt[i]+=1;
            if(i-2>=0){
                //subarrcnt 
                int cnt = subcnt[i-2];
                int subsum = prefixsum[i-2];
                prefixsum[i]+=subsum+(cnt*(nums[i-1]+nums[i]));
                subcnt[i]+=cnt;
            }
        }

        int sum =0;
        for(auto& i:prefixsum){
            sum+=i;
        }
        return sum;
    }
};