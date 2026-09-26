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
    TreeNode* invertTree(TreeNode* root) {
        // dfs -> swap child nodes of the root
        // return root 
        return dfs(root);
    }
    
    TreeNode* dfs(TreeNode* node){
        if(!node) return NULL;
        TreeNode* l = dfs(node->left);
        TreeNode* r = dfs(node->right);
        node->right =l;
        node->left =r; 
        return node;
    }

};