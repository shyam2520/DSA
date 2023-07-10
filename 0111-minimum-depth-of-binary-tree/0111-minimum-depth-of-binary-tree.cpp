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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root);
    }

    int dfs(TreeNode* node){
        if(!node->left && !node->right) return 1;
        int a=INT_MAX,b=INT_MAX;
        if(node->left) a=dfs(node->left);
        if(node->right) b=dfs(node->right);
        return 1+min(a,b);
    }
};