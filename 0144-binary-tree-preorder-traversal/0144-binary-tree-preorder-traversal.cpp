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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        stack<TreeNode*> stack; 
        while(node || stack.size()){
            if(node){
                res.push_back(node->val);
                stack.push(node);
                node=node->left;
            }
            else if(stack.size()){
                node=stack.top();
                stack.pop();
                if(node) node=node->right;
            }
        }

        return res;
    }
};