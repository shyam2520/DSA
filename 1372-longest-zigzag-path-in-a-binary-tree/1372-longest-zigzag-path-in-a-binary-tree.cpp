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
    int res = 0;
    int longestZigZag(TreeNode* root) {
        // do dfs 
        // pass the dir as parameter 
        // return only lst or rst based on dir 
        // int l = preorder(root->left,'l');
        // int r = preorder(root->right,'r');
        // res=max({res,l,r});
        preorder(root,'-');
        return res;
    }
    
    int preorder(TreeNode* node,char dir){
        if(!node) return 0;
        int l = preorder(node->left,'l');
        int r = preorder(node->right,'r');
        res=max({res,l,r});
        if(dir=='l') return 1+r;
        return 1+l;
    }

};