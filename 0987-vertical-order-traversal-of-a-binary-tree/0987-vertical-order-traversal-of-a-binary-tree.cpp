/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class compare{
    public: 
    using pii = pair<int,int>;
    bool operator()(const pii& a,const pii& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;       
    }
};
class Solution {
public:
    using pii=pair<int,int>;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pii>> dict;
        vector<vector<int>> res;
        verticaldfs(root,dict,0,0);
        for(auto& i:dict){
            sort(begin(i.second),end(i.second));
            vector<int> temp;
            for(auto& val:i.second) temp.push_back(val.second);
            res.push_back(temp);
        } 
        return res;
    }

    void verticaldfs(TreeNode* node,map<int,vector<pii>>& dict,int cidx,int ridx){
        if(!node) return ;
        dict[cidx].push_back({ridx,node->val});
        verticaldfs(node->left,dict,cidx-1,ridx+1);
        verticaldfs(node->right,dict,cidx+1,ridx+1);
    }
};