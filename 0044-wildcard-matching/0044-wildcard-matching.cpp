class Solution {
public:
    bool patternMatch(string& s, string& p,int i,int j,vector<vector<int>>& dp) {
        if(i==s.length() && j==p.length()) return true;
        if(j==p.length()) return false;
        if(i==s.length()){
            if(p[j]=='*') return patternMatch(s,p,i,j+1,dp);
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j]>0;
        if(p[j]=='*') {
            dp[i][j]=patternMatch(s,p,i+1,j,dp) || patternMatch(s,p,i+1,j+1,dp) || patternMatch(s,p,i,j+1,dp); // consider as empty
            return dp[i][j]>0;
        }
        if(p[j]=='?' || s[i]==p[j]){
            dp[i][j]=patternMatch(s,p,i+1,j+1,dp);
            return dp[i][j]>0;
        } 
        dp[i][j]=false;
        return dp[i][j]>0;
    }

    bool isMatch(string s,string p){
        int m = s.length(),n =p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[m][n]=true;
        for(int j=n-1;j>=0 && p[j]=='*';j--) dp[m][j]=true;
        // return patternMatch(s,p,0,0,dp);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(p[j]=='*'){
                    dp[i][j]=dp[i+1][j]||dp[i+1][j+1]||dp[i][j+1];
                }
                if(p[j]=='?' || s[i]==p[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
};