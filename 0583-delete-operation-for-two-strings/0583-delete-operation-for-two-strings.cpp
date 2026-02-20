class Solution {
public:
    int recursion(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(i==word1.size() || j==word2.size()) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=1+recursion(word1,word2,i+1,j+1,dp);
        return dp[i][j]=max(
            recursion(word1,word2,i+1,j,dp),
            recursion(word1,word2,i,j+1,dp)
        );
    }

    int minDistance(string word1, string word2) {
        // lcs , m-lcs + n-lcs 
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int lcs_len = recursion(word1,word2,0,0,dp);
        return (m-lcs_len) + (n-lcs_len);
    }
};