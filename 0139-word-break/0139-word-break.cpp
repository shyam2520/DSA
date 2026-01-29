class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> dict;
        vector<int> dp(s.length(),-1);
        for(auto& word:wordDict) dict[word]++;
        return dfs(s,0,dict,dp);
    }

    bool dfs(string& s,int start,unordered_map<string,int>& dict,vector<int>& dp){
        if(start==s.length()) return true;
        if(dp[start]!=-1) return dp[start]?true:false;
        bool res = false;
        for(int i=start;i<s.length();i++){
            string temp = s.substr(start,i-start+1);
            if(dict[temp]){
                res |= dfs(s,i+1,dict,dp);
                // if(res) return true;
            }
        }

        // return res;
        dp[start]=res?1:0;
        return res;
    }
};