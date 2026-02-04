class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // calcuaate sum(total_max) - sum(total_min) = res 
        // nse, dp -> total sub array min
        // repeat tot subarray max 
        int n = nums.size();
        stack<int> stack;
        vector<int> nse(n,n),nge(n,n);
        vector<long long> mins(n),maxs(n);
        for(int i=0;i<n;i++){
            while(stack.size() && nums[i]<nums[stack.top()]){
                int idx = stack.top();
                stack.pop();
                nse[idx]=i;
            }
            stack.push(i);
        }
        for(int i=n-1;i>=0;i--){
            if(nse[i]==n) mins[i]=(long long)nums[i]*(long long)(n-i);
            else mins[i] = (long long)nums[i]*(long long)(nse[i]-i) + mins[nse[i]];
        }
        long long total_mins = 0;
        for(auto& i:mins) total_mins+=i;

        // maxs 
        while(stack.size()) stack.pop();
        for(int i=0;i<n;i++){
            while(stack.size() && nums[i]>nums[stack.top()]){
                int idx = stack.top();
                stack.pop();
                nge[idx]=i;
            }
            stack.push(i);
        }
        for(int i=n-1;i>=0;i--){
            if(nge[i]==n) maxs[i]=(long long)nums[i]*(long long)(n-i);
            else maxs[i] = (long long)nums[i]*(long long)(nge[i]-i) + maxs[nge[i]];
        }
        long long total_maxs=0;
        for(auto& i:maxs) total_maxs+=i;

        return total_maxs-total_mins;
    }
};