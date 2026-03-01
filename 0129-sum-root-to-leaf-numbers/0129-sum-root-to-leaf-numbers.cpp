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
    int res =0;
    void dfs(TreeNode* node,int sum){
        if(!node) {
            res+=sum;
            return;
        }
        int val =node->val;
        if(!node->left && !node->right) {
            res+=sum*10+val;
            return;
        }
        dfs(node->left,sum*10+val);
        dfs(node->right,sum*10+val);
    }
    int sumNumbers(TreeNode* root) {
        // int total+=dfs(root);
        dfs(root,0);
        return res;
    }
};