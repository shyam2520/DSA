class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // next smaller element 
        stack<int> stack;
        int n = arr.size(),mod = 1e9+7;
        vector<int> nse(n,n);
        for(int i=0;i<n;i++){
            while(stack.size() && arr[stack.top()]>arr[i]) {
                nse[stack.top()]=i;
                stack.pop();
            }
            stack.push(i);
        }
        vector<int> dp(n);int res=0;
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            int nsev = nse[i];
            // if()
            dp[i]+=curr*(nsev-i);
            if(nsev!=n) dp[i]+=dp[nsev];
            res=(res%mod+(dp[i]%mod))%mod;
        }
        return res;

    }
};