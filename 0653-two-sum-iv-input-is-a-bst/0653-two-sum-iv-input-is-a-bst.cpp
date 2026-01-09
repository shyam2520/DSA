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
    // have two stacks (left , right)
    // 1. left - insert in ascending
    // 2. right - insert in descending
    // 3.  do two sum based on comparing the values  like we did for
    // vectors 
    void insertAsc(TreeNode* node,stack<TreeNode*>& stk){
        while(node){
            stk.push(node);
            node=node->left;
        }
    }

    void insertDesc(TreeNode* node,stack<TreeNode*>& stk){
        while(node){
            stk.push(node);
            node=node->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> left, right; 
        insertAsc(root,left);
        insertDesc(root,right);
        while(left.size() && right.size() && left.top()!=right.top()){
            int l=left.top()->val;
            int r=right.top()->val;
            // if(l>root->val || r<=root->val) return false;
            if(l+r==k && left.top()!=right.top()) return true;
            if(l+r>k){
                TreeNode* node = right.top();
                right.pop();
                insertDesc(node->left,right);
            }
            else {
                TreeNode* node = left.top();
                left.pop();
                insertAsc(node->right,left);
            }
        }
        return false;
    }
};