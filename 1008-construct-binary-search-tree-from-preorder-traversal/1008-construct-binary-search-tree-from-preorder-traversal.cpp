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
    // int preidx = -1;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // 1. push root to stack
        // 2. if preord[idx] < top then it is the left node & poush 
        // 3. if preord[idx]>top keep popping the values till we    have the first nowhich is greater then for prev pop connect it as   right node & push it
        return generateTree(preorder);
    }

    TreeNode* generateTree(vector<int>& preorder){
        stack<TreeNode*> stack; 
        TreeNode* root=new TreeNode(preorder.front());
        stack.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* node = new TreeNode(preorder[i]);
            if(stack.size() && stack.top()->val>node->val){
                stack.top()->left = node; 
                stack.push(node);
            }
            else {
                TreeNode* prev=NULL;
                while(stack.size() && stack.top()->val<node->val){
                    prev=stack.top();
                    stack.pop();
                }
                if(prev) prev->right=node;
                stack.push(node);
            }
        }
        return root;
    }

};