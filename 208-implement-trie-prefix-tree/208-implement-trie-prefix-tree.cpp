class Trie {
    unordered_map<char,Trie*> dict;
    bool eod;
    Trie* curr;
public:
    Trie() {
        // curr=new Trie();
        curr=this;
        eod=false;
        // return curr;
    }
    
    void insert(string word) {
        // cout<<curr<<endl;
        Trie* temp=curr;
        for(auto& i:word)
        {
            if(temp->dict.find(i)!=temp->dict.end())
                temp=temp->dict[i];
            else 
            {
                temp->dict[i]=new Trie();
                temp=temp->dict[i];
            }
                
        }
        temp->eod=true;
    }
    
    bool search(string word) {
        Trie* temp=curr;
        for(auto& i:word)
        {
            if(temp->dict.find(i)==temp->dict.end()) return false;
            temp=temp->dict[i];
        }
        return temp->eod;
    }
    
    bool startsWith(string prefix) {
        Trie* temp=curr;
        for(auto& i:prefix)
        {
            if(temp->dict.find(i)==temp->dict.end()) return false;
            temp=temp->dict[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */