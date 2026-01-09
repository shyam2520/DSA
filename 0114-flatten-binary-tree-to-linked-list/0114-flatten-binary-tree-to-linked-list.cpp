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
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        dfs(root);
    }

    void dfs(TreeNode* node){
        if(!node) return ; 
        TreeNode* rst = node->right;
        if(prev){
            prev->right = node;
        } 
        prev=node;
        dfs(node->left);
        node->left=NULL;
        dfs(rst);
    }
};