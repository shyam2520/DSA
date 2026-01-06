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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res; 
    }
    int height(TreeNode* node){
        if(!node) return 0; 
        int lst = height(node->left);
        int rst = height(node->right);
        res = max(res,lst+rst);
        return 1+max(lst,rst);
    }
};