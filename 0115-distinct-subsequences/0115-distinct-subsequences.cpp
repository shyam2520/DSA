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
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // for(int i=0;i<m;i++) dp[i][n]=1;
        return recursion(s,t,0,0,dp);
    }
};