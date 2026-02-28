class Solution {
public:
    int genSubArr(vector<int>& arr,int& k,int start,vector<int>& dp){
        if(start==arr.size()) return 0;
        if(dp[start]!=-1) return dp[start];
        int curr=0;
        int res = 0;
        for(int i=start;i<arr.size() && (i-start)<k;i++){
            curr=max(curr,arr[i]);
            res=max(
                res,
                curr*(i-start+1)+genSubArr(arr,k,i+1,dp)
                );
        }
        return dp[start]=res;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return genSubArr(arr,k,0,dp);
    }
};