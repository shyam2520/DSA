class Solution {
public:
    int minDistance(string word1, string word2) {
       // int res=lcs(word1,word2,word1.length(),word2.length());
        // return word1.length()+word2.length() - 2*res;
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return m+n-2*dp[m][n];
        
    }
    
    // int lcs(string& word1,string& word2,int m,int n)
    // {
    //     if(m==0 || n==0 ) return 0;
    //     if(word1[m-1]==word2[n-1]) return 1+lcs(word1,word2,m-1,n-1);
    //     return max(lcs(word1,word2,m-1,n),lcs(word1,word2,m,n-1));
    // }
};