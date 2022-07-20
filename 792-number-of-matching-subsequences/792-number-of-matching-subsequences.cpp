class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<string>> dict(26);
        for(auto& word:words) dict[word[0]-'a'].push_back(word);
        int ans=0;
        for(auto& c:s)
        {
            vector<string> temp=dict[c-'a'];
            dict[c-'a'].clear();
            for(auto& i:temp)
            {
                string curr=i.substr(1);
                if(curr.size()==0) ans++;
                else dict[curr[0]-'a'].push_back(curr);
            }
        }
        return ans;
    }
};