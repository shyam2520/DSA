class Solution {    
public:
    bool valid_subst(vector<int>& mp){
        int cnt=-1;
        for(int i=0;i<26;i++){
            if(!mp[i]) continue; 
            if(mp[i] && cnt==-1) cnt=mp[i];
            else if(mp[i] && mp[i]!=cnt) return false; 
        }
        return true;
    }
    int longestBalanced(string s) {
        int res =1;
        for(int i=0;i<s.size();i++){
            vector<int> dict(26); 
            // unordered_map<char,int> dict; 
            dict[s[i]-'a']++; 
            for(int j=i+1;j<s.size();j++){
                dict[s[j]-'a']++; 
                if(valid_subst(dict)) res=max(res,j-i+1);
            }
        }
        return res;
    }
};