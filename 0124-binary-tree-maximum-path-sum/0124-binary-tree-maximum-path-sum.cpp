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
    // int res = 0;
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        calMax(root,res);
        return res;
    }

    int calMax(TreeNode* node,int& res){
        if(!node) return -10000;
        int lst = calMax(node->left,res);
        int rst = calMax(node->right,res);
        res=max({res,node->val,lst+node->val,rst+node->val,lst+rst+node->val});
        return max(node->val+max(lst,rst),node->val);
    }

};