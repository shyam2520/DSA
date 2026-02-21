class Solution {
public:
    int dist(string& w1,string& w2,int i,int j,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return dp[i][j]=dist(w1,w2,i-1,j-1,dp);
        return dp[i][j]=1+min({
            dist(w1,w2,i-1,j-1,dp),
            dist(w1,w2,i,j-1,dp),
            dist(w1,w2,i-1,j,dp)
        });
    }

    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min({
                        dp[i-1][j-1],dp[i][j-1],dp[i-1][j]
                    });
                }
            }
        }
        return dp[m][n];

        // return dist(word1,word2,m-1,n-1,dp);
    }
};