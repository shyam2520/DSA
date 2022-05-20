/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val) return root;
        if(root->val==q->val) return root;
        TreeNode* lst=lowestCommonAncestor(root->left,p,q);
        TreeNode* rst=lowestCommonAncestor(root->right,p,q);
        return lst&&!rst?lst:!lst&&rst?rst:lst&&rst?root:NULL;
    }
};