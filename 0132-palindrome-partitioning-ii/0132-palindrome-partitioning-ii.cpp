class Solution {
public:
    int checkPalindrome(string& s,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        while(i<j && s[i]==s[j]){
            // dp[i][j]=1;
            i++;j--;
            // if(dp[i][j]!=-1) return dp[i][j];
        }
        return dp[i][j]=(i>=j); // O(n)
    }
    int minCut(string s) {
        // aab 
        int n = s.length();
        vector<int> dp(n+1,0);
        vector<vector<int>> paldp(n,vector<int>(n,-1));
        for(int start=s.length()-1;start>=0;start--){
            int cuts = 2100;
            for(int i=start;i<s.length();i++){
                if(checkPalindrome(s,start,i,paldp)){
                    cuts= min(cuts,1+dp[i+1]);
                }
            }
            dp[start]=cuts;
        }
        return dp[0]-1;
        // int strcnt= genCuts(s,0,dp);
        // return strcnt-1;
    }
};