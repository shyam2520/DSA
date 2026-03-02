class Solution {
public:
    int getFactorial(int n,vector<int>& dp){
        if(n<=1) return 1;
        return dp[n]=getFactorial(n-1,dp)*n; 
    }

    bool isDigitorialPermutation(int n) {
        vector<int> dp(10,0);
        dp[0]=dp[1]=1;
        getFactorial(9,dp);
        vector<int> cnt(10,0);
        int ans = 0;
        while(n){
            cout<<dp[n%10]<<endl;
            ans+=dp[n%10];
            cnt[n%10]++;
            n/=10;
        }
        // cout<<ans<<endl;
        while(ans){
            cnt[ans%10]--;
            ans/=10;
        }
        for(auto& i:cnt) if(i) return false;

        return true;
    }
};