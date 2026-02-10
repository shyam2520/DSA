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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        res.push_back(root->val);
        dfs(root->left,'l');
        dfs(root->right,'r');
        return res;
    }

    void dfs(TreeNode* node,char dir){
        if(!node) return ;
        if(!node->left && !node->right){
            res.push_back(node->val);
            return;
        }
        // left
        if(dir=='l'){
            res.push_back(node->val);
            dfs(node->left,dir);
            char new_dir = node->left?'-':'l';
            dfs(node->right,new_dir);
            return;
        }
        // right 
        if(dir=='r'){
            char new_dir=node->right?'-':'r';
            dfs(node->left,new_dir);
            dfs(node->right,dir);
            res.push_back(node->val);
            return;
        }
        // null 
        dfs(node->left,dir);
        dfs(node->right,dir);
    }
};