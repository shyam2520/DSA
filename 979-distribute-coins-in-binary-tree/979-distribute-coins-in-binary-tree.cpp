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
    int moves=0;
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
    vector<int> dfs(TreeNode* root)
    {
        if(!root) return {0,0};
        
        vector<int> left=dfs(root->left);
        vector<int> right=dfs(root->right);
        
        moves+=abs(left[0]-left[1])+abs(right[0]-right[1]);
        
        return {left[0]+right[0]+1,left[1]+right[1]+ root->val};
    }
};