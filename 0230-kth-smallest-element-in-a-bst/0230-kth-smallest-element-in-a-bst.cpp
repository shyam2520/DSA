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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* node = root; 
        while(stack.size() || node){
            if(node){
                stack.push(node);
                node=node->left;
            }
            else{
                TreeNode* top = stack.top();
                stack.pop();
                k--;
                if(!k) return top->val;
                node = top->right;
            }
        }
        return -1;
    }
};