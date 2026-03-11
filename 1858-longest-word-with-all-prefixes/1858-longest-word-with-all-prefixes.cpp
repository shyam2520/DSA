class Trie{
    vector<Trie*> dict;
    bool eow;
    public:
    Trie(){
        dict.resize(26,NULL);
        this->eow=false;
    }
    void insert(string& word){
        Trie* curr = this;
        for(auto& ch:word){
            if(curr->dict[ch-'a']==NULL) curr->dict[ch-'a']=new Trie();
            curr=curr->dict[ch-'a'];
        }
        curr->eow=true;
    }
    bool search(string& word){
        Trie* curr = this;
        for(auto& ch:word){
            if(!curr->dict[ch-'a']) return false; 
            curr = curr->dict[ch-'a'];
            if(!curr->eow) return false;
        }
        return curr->eow;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        string res="";
        Trie* cpy = trie;
        sort(begin(words),end(words));
        for(auto& word:words)
        {
            trie->insert(word);
            trie = cpy;
            if(trie->search(word)){
                if(res.size()==word.size() && res>word) res=word;
                if(res.size()<word.size()) res=word;
            }
        }
        return res;
    }
};