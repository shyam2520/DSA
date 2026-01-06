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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack; 
        TreeNode* node = root; 
        vector<int> res;
        while( node || stack.size()){
            if(node){
                stack.push(node);
                node=node->left;
            }
            else{
                TreeNode* curr = stack.top()->right;
                if(curr!=NULL){
                    node = curr;
                } 
                else{
                    res.push_back(stack.top()->val);
                    curr=stack.top();
                    stack.pop(); 
                    while(stack.size() && stack.top()->right==curr)
                    {
                        curr=stack.top();
                        res.push_back(curr->val);
                        stack.pop();
                    }
                    // if(stack.size()) node=stack.top()->right;
                }
            }
        }
        return res;
    }
};