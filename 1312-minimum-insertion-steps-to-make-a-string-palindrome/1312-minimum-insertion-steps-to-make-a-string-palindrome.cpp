class Solution {
public:
    int recursion(string& s,int l,int r,vector<vector<int>>& dp){
        if(l>r) return 0;
        if(l==r) return 1; 
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) return 2+recursion(s,l+1,r-1,dp);
        return dp[l][r]=max(
            recursion(s,l+1,r,dp),
            recursion(s,l,r-1,dp)
        );
    }

    int minInsertions(string s) {
        // find the longest pal subseq
        // n - longpal = remaining are palindrom 
        int l=0,n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int i=n;i>=1;i--){
        //     for(int j=1;j<=n;j++){
        //         int l=i-1;
        //         int r=j-1;
        //         if(l==r) dp[i][j]=1;
        //         else if(s[l]==s[r]) dp[i][j]=2+dp[]
        //     }
        // }

        int pal =  recursion(s,l,n-1,dp);
        return n-pal;
    }
};