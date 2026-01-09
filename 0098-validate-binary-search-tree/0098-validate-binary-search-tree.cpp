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
    bool isValidBST(TreeNode* node,int min_val=INT_MIN,int max_val = INT_MAX) {
        //1. at each node you set range it has to between those values
        //2. and as you move left or right you update those ranges 
        if(!node) return true;
        if(!(node->val>min_val && node->val<max_val)) return false;
        return isValidBST(node->left,min_val,node->val) && 
            isValidBST(node->right,node->val,max_val);

    }
};