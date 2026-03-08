class Trie {
public:
    bool eow; 
    vector<Trie*> dict;
    Trie() {
        dict.resize(26,NULL);
        eow=false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        // Trie* prev = curr;
        for(auto& ch:word){
            // dict[ch-'a']
            if(!curr->dict[ch-'a']){
                curr->dict[ch-'a']=new Trie();
            }
            // prev=curr;
            curr=curr->dict[ch-'a'];
        }
        curr->eow=true;
    }
    
    bool search(string word) {
        Trie* curr=this; 
        for(auto& ch:word){
            if(!curr->dict[ch-'a']) return false; 
            curr=curr->dict[ch-'a'];
        }
        return curr->eow; 
    }
    
    bool startsWith(string prefix) {
        Trie* curr=this;
        for(auto& ch:prefix){
            if(!curr->dict[ch-'a']) return false; 
            curr=curr->dict[ch-'a'];
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

 /*
*/