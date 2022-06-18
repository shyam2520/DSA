class WordFilter {
    unordered_map<string,int> dict;
public:
    WordFilter(vector<string>& words) {
        string suffix,prefix,word;
        for(int i=0;i<words.size();i++)
        {
            word=words[i];
            for(int j=1;j<=word.length();j++)
            {
                prefix=word.substr(0,j);
                for(int k=1;k<=word.length();k++)
                {
                    suffix=word.substr(word.length()-k,k);
                    // cout<<prefix+"#"+suffix<<endl;
                    dict[prefix+"#"+suffix]=i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return dict.count(prefix+"#"+suffix)?dict[prefix+"#"+suffix]:-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */