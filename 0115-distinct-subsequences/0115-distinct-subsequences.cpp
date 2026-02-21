class Solution {
public:
    int recursion(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j]=recursion(s,t,i+1,j+1,dp)+recursion(s,t,i+1,j,dp);
        }
        return dp[i][j]=recursion(s,t,i+1,j,dp);
    }

    int numDistinct(string s, string t) {
        // if match take or not , if not match no take 
        int m = s.size(),n = t.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        next[n]=1;
        curr[n]=1;
        for(int i=m-1;i>=0;i--){

            for(int j=n-1;j>=0;j--){
                if(s[i]==t[j]){
                    curr[j]=(long)next[j+1]+(long)next[j];
                }
                else curr[j]=next[j];
            }
            next = curr;
            curr[n]=1;
        }
        return next[0];
    }
};