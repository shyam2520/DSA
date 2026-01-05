class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        vector<int> nse(n,n);
        stack<int> stack;
        for(int i=0;i<n;i++){
            while(stack.size() && arr[stack.top()]>arr[i]){
                nse[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        int res = 0;
        for(int i=n-1;i>=0;i--){
            int nseidx = nse[i];
            int sum_min = 0;
            if(nseidx==n){
                sum_min = ((arr[i]%mod)*((n-i)%mod))%mod;
            }
            else{
                sum_min = ((arr[i]%mod)*((nseidx-i)%mod))%mod+(dp[nseidx])%mod;
            }
            dp[i] = sum_min;
            res=res%mod + dp[i]%mod;
        }

        return res;
    }
};