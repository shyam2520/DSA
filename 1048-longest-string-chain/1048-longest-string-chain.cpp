class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(begin(words),end(words),[](string& a,string& b){
            return a.length()<b.length();
        });
        int ans=0;
        unordered_map<string,int> dict;
        for(auto& word:words)
        {
            int res=0;
            for(int i=0;i<word.length();i++)
            {
                string temp=word.substr(0,i)+word.substr(i+1);
                res=max(res,dict.find(temp)==dict.end()?1:dict[temp]+1);
            }
            dict[word]=res;
            ans=max(ans,res);
        }
        return ans;
    }
};