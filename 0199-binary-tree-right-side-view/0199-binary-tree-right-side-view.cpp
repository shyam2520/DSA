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
class Solution {
public:
    map<int,TreeNode*> dict;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        vector<int> res;
        for(auto& i:dict){
            res.push_back(i.second->val);
        }
        return res;
    }

    void dfs(TreeNode* node,int ridx){
        if(!node) return;
        dict[ridx]=node;
        dfs(node->left,ridx+1);
        dfs(node->right,ridx+1);
    }
};