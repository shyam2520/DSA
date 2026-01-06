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
    // 1. node traverse left->right->root
    // 2. we have to push the final values into the stack at popping time 
    // 3. catch is if we do it like pre/in order we end up printing root first 
    // 4. so he we need to ensure that a root is print only after its lst & rst are parse
    // 5. create pair - (node,'l/r') l -> lst is parsed, r -> rst is parsed 
    // 6. only pop out when the top value of stack is 'r'  

    vector<int> res;
    using ptc= pair<TreeNode*,char>;
    vector<int> postorderTraversal(TreeNode* root) {
        stack<ptc> stack; 
        TreeNode* node = root; 
        while(node || stack.size()){
            if(node){
                // 
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