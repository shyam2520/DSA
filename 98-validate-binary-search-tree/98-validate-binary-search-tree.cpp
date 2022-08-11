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
    bool isValidBST(TreeNode* root) {
        // cout<<LINT_MIN<<endl;
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
    
    bool dfs(TreeNode* node,long long int l,long long int r)
    {
        if(!node) return true;
        if( node->val <= l ||  node ->val>=r) return false;
        
        bool left = dfs(node->left, l,node->val);
        bool right=dfs(node->right,node->val,r);
        
        return left && right;
    }
};