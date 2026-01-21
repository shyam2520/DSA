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
        return dfs(root,INT_MIN,INT_MAX);
    }

    bool dfs(TreeNode* node,int low,int high){
        if(!node) return true; 

        if(node->val<=low || node->val>=high) return false; 

        bool lst = dfs(node->left,low,node->val); 
        if(!lst) return false;
        bool rst = dfs(node->right,node->val,high); 
        return lst&&rst;

    }
};