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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* node){
        if(!node) return 0;
        int lst = dfs(node->left);
        int rst = dfs(node->right); 
        if(abs(lst-rst)>1) res=false;
        return 1+max(lst,rst);
    }
};