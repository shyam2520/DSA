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
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        // if(!subroot) return true;
        // if(!root) return false;
        return dfs(root,subroot);
    }

    bool compare(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val!=b->val) return false;
        return compare(a->left,b->left) && compare(a->right,b->right);
    }

    bool dfs(TreeNode* node,TreeNode* subnode){
        if(!node) return false;
        if(node->val==subnode->val && compare(node,subnode)) return true;
        return dfs(node->left,subnode) || dfs(node->right,subnode);
    }
};