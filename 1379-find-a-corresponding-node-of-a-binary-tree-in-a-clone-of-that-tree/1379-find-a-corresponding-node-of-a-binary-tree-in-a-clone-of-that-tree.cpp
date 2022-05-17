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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return search(cloned,target);
    }
    TreeNode* search(TreeNode* root,TreeNode* target)
    {
        if(!root) return NULL;
        if(root->val==target->val) return root;
        TreeNode* lst=search(root->left,target);
        TreeNode* rst=search(root->right,target);
        return !lst && rst?rst:lst && !rst?lst:NULL;
    }
};