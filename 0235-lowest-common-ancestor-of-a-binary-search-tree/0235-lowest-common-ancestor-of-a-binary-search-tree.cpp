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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 3 possiblities 
    // 1. both are in lst 
    // 2. both are in rst 
    // 3. they are split in either in the case current is the ancestor 
        return lca(root,p,q);
    }

    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node) return NULL; 
        
        if(node==p || node == q) return node;
        int max_val = max({p->val,q->val});
        int min_val = min({p->val,q->val});
        if(min_val<node->val && max_val<node->val){
            return lca(node->left,p,q);
        }
        else if(min_val>node->val && max_val>node->val){
            return lca(node->right,p,q);
        }
        return node;
    }

};