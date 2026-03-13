class Trie{
    vector<Trie*> dict;
    public:
    Trie(){
        dict.resize(2,NULL);
    }

    void insert(int& num){
        Trie* curr = this;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(curr->dict[bit]==NULL) curr->dict[bit]=new Trie();
            curr=curr->dict[bit]; 
        }
    }

    int getMax(int& num)
    {
        Trie* curr = this;
        long res=0; 
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->dict[!bit]){
                res^=1;
                curr=curr->dict[!bit];
            }
            else{
                curr=curr->dict[bit];
            }
            res<<=1;
        }
        res=res>>1;
        return res;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // store all the number in the tries 
        // every incoming number check if there is opposite value if you have set bit if not unset 
        Trie* root = new Trie();
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i==0) root->insert(nums[i]);
            else{
                res=max(res,root->getMax(nums[i]));
                root->insert(nums[i]);
            }
        }   
        return res;
    }
};