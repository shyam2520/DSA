class Solution {
public:
    bool isValid(string& word){
        char f=word[0];
        char b=word.back();
        if(f!='a' && f!='e' && f!='i' && f!='o' && f!='u') return false; 
        if(b!='a' && b!='e' && b!='i' && b!='o' && b!='u') return false;
        return true;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // update the array  to number based on the condition 
        int n = words.size();
        vector<int> vcnt(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=isValid(words[i])?1:0;
            vcnt[i]=cnt;
        }
        int l,r;
        vector<int> res;
        for(int i=0;i<queries.size();i++){
            l=queries[i][0]-1>=0?vcnt[queries[i][0]-1]:0;
            r=vcnt[queries[i][1]];
            res.push_back(r-l);
        }
        return res;

    }
};