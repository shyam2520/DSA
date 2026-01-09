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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 1. find the close the value to val either lesser or greater
        // 2. based on the value set the new val either on the left or right    
        if(!root) return new TreeNode(val);
        TreeNode *prev = root,*node = root;
        while(node){
            prev=node; 
            if(node->val>val) node=node->left;
            else node = node->right;
        }
        if(prev->val>val){
            prev->left = new TreeNode(val);
        }
        else prev->right = new TreeNode(val);
        return root;
    }
};