class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> dict(26);
        unordered_map<string,bool> res;
        for(int i=0;i<s.length();i++) dict[s[i]-'a'].push_back(i);
        int curridx,count=0;
        bool flag;
        for(auto& word:words)
        {
            flag=true;
            curridx=-1;
            if(res.count(word)) 
            {
                count+=res[word]?1:0;
                continue;
            }
            for(int i=0;i<word.length();i++)
            {
                // vector<int> pos=dict[word[i]-'a'];
                auto p=upper_bound(begin(dict[word[i]-'a']),end(dict[word[i]-'a']),curridx);
                if(p==dict[word[i]-'a'].end())
                {
                    flag=false;
                    break;
                }
                curridx=*p;
            }
            if(flag) count++;
            res[word]=flag;
        }
        
        return count;
            
    }
};