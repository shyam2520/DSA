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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. find the node 
        // 2. check if no child or one child exists return accordingly 
        // 3. if both child exists return inorder successor and replace
        // that with root value then from start searching from root->right for 
        // successor value when that value is found that would be delete (thats duplicate )

        return delNode(root,key);
    }

    TreeNode* delNode(TreeNode* node,int& key){
        if(!node) return NULL; 
        if(node->val>key) {
            node->left=delNode(node->left,key);
        }
        else if(node->val<key){
            node->right=delNode(node->right,key);
        }
        else{
            if(!node->left && !node->right){
                delete node;
                return NULL; 
            } 
            if(!node->left || !node->right){
                TreeNode* res = node->left?node->left:node->right;
                delete node;
                return res;
            }
            // find inorder success; 
            TreeNode* successor = node->right; 
            while(successor->left) successor = successor->left; 
            node->val = successor->val; 
            node->right = deleteNode(node->right,successor->val);

        }
        return node;
    }

};