class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // take min(left col, top row , diag left) + 1 
        // convert char to integer matrix 
        int m=matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int res=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                int curr = matrix[i][j]-'0';
                if(!curr) continue;
                int left = j-1>=0?dp[i][j-1]:0;
                int top = i-1>=0?dp[i-1][j]:0;
                int diag = i-1>=0 && j-1>=0?dp[i-1][j-1]:0;
                dp[i][j]=min({left,top,diag})+1;
                res=max(res,dp[i][j]);
            }
        } 
        return res*res;
    }
};