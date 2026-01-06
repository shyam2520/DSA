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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack; 
        TreeNode *node = root; 
        vector<int> res;
        while(node || stack.size()){
            if(node){
                stack.push(node);
                node=node->left;
            }
            else{
                node = stack.top();
                stack.pop();
                res.push_back(node->val);
                node=node->right;
            }
        }
        return res;
    }

    
};