class Solution {
public:
    bool searchString(string& s,unordered_map<string,int>& dict,int l,int r ,string temp,int& max_length,vector<vector<int>>& dp){
        if(temp.length()>max_length) return false;
        if(r==s.length()) return !temp.size();
        if(dp[l][r]!=-1) return dp[l][r];
        temp.push_back(s[r]);
        bool a = searchString(s,dict,l,r+1,temp,max_length,dp);
        if(dict.count(temp)){
            bool b= searchString(s,dict,r+1,r+1,"",max_length,dp);
            dp[l][r]=a||b?1:0;
            return dp[l][r];
        }
        dp[l][r]= a?1:0;
        return dp[l][r];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>  dict;
        int max_length=0;
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(auto& i:wordDict){
            max_length=max(max_length,(int)i.size());
            dict[i]++;
        } 
        return searchString(s,dict,0,0,"",max_length,dp);
    }
};