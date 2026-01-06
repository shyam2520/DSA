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
    using ptc= pair<TreeNode*,char>;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<ptc> stack; 
        TreeNode* node = root; 
        while(node || stack.size()){
            if(node){
                stack.push({node,'l'});
                node=node->left;
            }
            else if(stack.size())
            {
                ptc top = stack.top(); 
                stack.pop();
                if(top.second=='l'){
                    node=top.first->right;
                    stack.push({top.first,'r'});
                }
                else{
                    res.push_back(top.first->val);
                }
            }
        }

        return res;
    }
};