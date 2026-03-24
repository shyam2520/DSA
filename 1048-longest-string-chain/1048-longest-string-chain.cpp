class Solution {
public:

    bool wordcompare(string& a,string& b){
        int anc=0,miss=0;
        for(int i=0;i<b.size();i++){
            if(a[anc]==b[i]) anc++;
            else miss++;
        }
        return miss<2;
    }

    int longestStrChain(vector<string>& words) {
        // set(words)
        //  a->  [ba,da,db] -> []
        // n*n -> largest word * m 
        unordered_map<int,vector<string>> len_d;
        for(auto& i:words) len_d[i.size()].push_back(i);
        unordered_map<string,int> dp;
        for(auto& i:words){
            dfs(i,len_d,dp);
        }
        int res = -1;
        for(auto& i:dp) res=max(res,i.second);
        return res;
    }

    int dfs(string pre,unordered_map<int,vector<string>>& dict,unordered_map<string,int>& dp){
        int n = pre.size();
        // if(dict.find(n+1)==dict.end()){
        //     dp[pre]=1;
        //     return 0;
        // } 
        if(dp.count(pre)) return dp[pre];
        int res=1;
        for(auto& wrd:dict[n+1]){
            if(wordcompare(pre,wrd)){
                res=max(res,1+dfs(wrd,dict,dp));
            }
        }
        return dp[pre]=res;
    }

};