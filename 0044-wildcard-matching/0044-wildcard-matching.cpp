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
        // if(j==p.length() || i==s.length()) return false;
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
        if(!s.length()){
            for(auto& i:p) if(i!='*') return false;
            return true;
        }
        int m = s.length(),n =p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return patternMatch(s,p,0,0,dp);
    }
};