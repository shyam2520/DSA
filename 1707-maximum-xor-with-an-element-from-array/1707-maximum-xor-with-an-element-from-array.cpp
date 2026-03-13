class Trie{
    vector<Trie*> dict;
    public:
    Trie(){
        dict.resize(2,NULL);
    }

    void insert(int& num){
        Trie* root = this;
        for(int i=31;i>=0;i--){
            int bit = (num>>i )& 1;
            if(root->dict[bit]==NULL) root->dict[bit]=new Trie();
            root=root->dict[bit];
        }
    }

    int getMax(int& num){
        long res=0;
        Trie* root=this;
        for(int i=31;i>=0;i--){
            int bit= (num>>i )& 1;
            if(root->dict[!bit]){
                res^=1;
                root=root->dict[!bit];
            }
            else root=root->dict[bit];
            res<<=1;
        }
        res>>=1;
        return res;
    }

};

class compare{
    public:
    bool operator()(vector<int>& a,vector<int>& b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // sort the queries based on second value 
        // sort the numbers 
        // store all the numbers first till less<=1 
        // the getmax for the queries and then increment queries
        Trie* root = new Trie();
        sort(begin(nums),end(nums));
        vector<vector<int>> qidx;
        for(int i=0;i<queries.size();i++){
            qidx.push_back({queries[i][0],queries[i][1],i});
        }

        sort(begin(qidx),end(qidx),compare());
        vector<int> ans(queries.size());
        int j=0;


        for(int i=0;i<qidx.size();i++){
            if(nums.front()>qidx[i][1]){
                ans[qidx[i][2]]=-1;
                continue;
            }
            while(j<nums.size() && nums[j]<=qidx[i][1]){
                root->insert(nums[j]);
                j++;
            }
            ans[qidx[i][2]]=root->getMax(qidx[i][0]);
        }
        return ans;
    }
};