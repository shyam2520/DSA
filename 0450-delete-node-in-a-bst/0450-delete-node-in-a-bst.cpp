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
        if(!root) return NULL; 
        TreeNode* dummy = new TreeNode(-1); 
        dummy->left = root; 
        // if node to be delete is the key then make its lst or rst as root  
        // for a node 
        dummy->left = delNode(root,key);

        return dummy->left; 
    }

    TreeNode* delNode(TreeNode* node, int key){
        if(!node) return NULL; 
        // if that 
        if(node->val == key){
            // find replacement 
            // check if leaf return NULL; 
            TreeNode* delNode = node;
            if(!node->left && !node->right) return NULL; 
            if(node->left){
                TreeNode* prev = node->left ; 
                node = node->left;
                while(node->right){
                    prev=node;
                    node=node->right;
                }
                if(prev!=node){
                    prev->right = node->left;
                } 
                if(node!=delNode->left) node->left=delNode->left;
                if(node!=delNode->right) node->right=delNode->right;
                delete(delNode);
                return node;
            }
            else{
                TreeNode* prev = node->right; 
                node = node->right; 
                while(node->left){
                    prev=node; 
                    node=node->left; 
                }
                if(prev!=node){
                    prev->left=node->right;
                }
                if(node!=delNode->left) node->left=delNode->left;
                if(node!=delNode->right) node->right=delNode->right;
                delete(delNode);
                return node;
            }
        }   
        if(node->val>key){
            node->left = delNode(node->left,key);
        } 
        else node->right = delNode(node->right,key);
        return node;
    }
};