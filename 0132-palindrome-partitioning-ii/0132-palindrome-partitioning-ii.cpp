class Solution {
public:
    int checkPalindrome(string& s,int i,int j){
        while(i<j && s[i]==s[j]){
            i++;j--;
        }
        return i>=j; // O(n)
    }
    int genCuts(string& s,int start,vector<int>& dp){
        if(start==s.length()) return 0;
        if(dp[start]!=-1) return dp[start];
        int cuts = 2100; 
        for(int i=start;i<s.length();i++){
            // start -> i 
            if(checkPalindrome(s,start,i)){
                cuts = min(cuts,1+genCuts(s,i+1,dp));
            }
        }
        return dp[start]=cuts;
    }

    int minCut(string s) {
        // aab 
        vector<int> dp(s.length()+1,0);
        for(int start=s.length()-1;start>=0;start--){
            int cuts = 2100;
            for(int i=start;i<s.length();i++){
                if(checkPalindrome(s,start,i)){
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