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
        if(!root) return NULL; 
        return traverse(root,p,NULL);
    }

    // when you find the element possible next success
    // if parent > child (lst) -> either parent or left most child of its rst 
    // if parent < child ( rst) -> left most child 
    // if root ==p the 

    TreeNode* traverse(TreeNode* node, TreeNode* p, TreeNode* larger){
        if(!node) return NULL; 
        if(node==p){
            // check if its lst or rst 
            if(larger){
                TreeNode* succ = inordersuccessor(node->right);
                return succ?succ:larger;
            }
            else return inordersuccessor(node->right);
        }
        if(node->val>p->val) return traverse(node->left,p,node);
        else return traverse(node->right,p,larger);

    }

    TreeNode* inordersuccessor(TreeNode* node){
        if(!node) return NULL; 
        while(node->left) node=node->left;
        return node;
    }
};