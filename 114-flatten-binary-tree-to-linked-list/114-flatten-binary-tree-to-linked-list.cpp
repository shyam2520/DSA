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
    void flatten(TreeNode* root) {
        if(!root) return ;
        traverse(root);
        // return root;
    }
    
    TreeNode* traverse(TreeNode* root)
    {
        if(!root) return root;
        TreeNode* left=traverse(root->left);
        TreeNode* right=traverse(root->right);
        if(root->left) 
        {
            left->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        return right?right:left?left:root;
        
        
    }
};