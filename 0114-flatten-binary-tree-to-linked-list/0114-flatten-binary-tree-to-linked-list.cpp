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
    queue<TreeNode*> q;
    void flatten(TreeNode* root) {
        preorder(root);
    }
    
    void preorder(TreeNode* node){
        if(!node) return ; 
        q.push(node);
        TreeNode* left = node->left;
        node->left = NULL; 
        TreeNode* right = node->right;
        node->right = NULL;
        if(q.size()>1){
            TreeNode* top = q.front();
            q.pop();
            top->right = q.front();
        }
        if(left) preorder(left);
        if(right) preorder(right);
    }
        

};