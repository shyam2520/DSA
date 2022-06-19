class Solution {
    unordered_map<char,Solution*> dict;
    vector<string> suggestions;
    Solution* curr;
public:
    Solution(){
        curr=this;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(begin(products),end(products));
        Solution* temp;
        // cout<<curr<<endl;
        for(auto& product:products)
        {
            temp=curr;
            // cout<<product<<endl;
            for(auto& ch:product)
            {
                if(temp->dict.find(ch)==temp->dict.end())
                {
                    temp->dict[ch]=new Solution();
                    temp=temp->dict[ch];
                    if(temp->suggestions.size()<3) temp->suggestions.push_back(product);
                    
                }
                else{
                    temp=temp->dict[ch];
                    if(temp->suggestions.size()<3) temp->suggestions.push_back(product);
                }
            }
            // if(temp->suggestions.size()<3) temp->suggestions.push_back(product);
        }
        
        vector<vector<string>> res;
        int i;
        for(i=0;i<searchWord.length();i++)
        {
            if(curr->dict.find(searchWord[i])!=curr->dict.end())
            {
                curr=curr->dict[searchWord[i]];
                res.push_back(curr->suggestions);
            }
            else break;
            
        }
        for(;i<searchWord.length();i++) res.push_back({});
        // res.push_back(curr->suggestions);
        return res;
        
    }
};