/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *node = root,*successor = NULL; 
        while(node){
            if(node==p){
                TreeNode *temp = node->right; 
                while(temp && temp->left) temp=temp->left;
                return temp?temp:successor;
            }
            if(node->val>p->val){
                successor=node;
                node=node->left;
            }
            else {
                node=node->right;
            }
        }
        return NULL; 
    }
};