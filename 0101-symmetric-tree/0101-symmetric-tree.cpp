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

    bool isSymmetric(TreeNode* root) {
        // make the problem as two differnet tree and compare it 
        // rst would right & left 
        // lst would left & right
        return dfssym(root->left,root->right);
    }

    bool dfssym(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;
        if((a && !b) || (b && !a)) return false;
        if(a->val !=b->val) return false;
        return dfssym(a->left,b->right) && dfssym(a->right,b->left);
    }
};