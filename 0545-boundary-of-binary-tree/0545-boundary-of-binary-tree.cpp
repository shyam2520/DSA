/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),   right(right) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        res.push_back(root->val);
        // left 
        dfs(root->left,'l');
        // right
        dfs(root->right,'r');
        return res;
    }

    void dfs(TreeNode* node,char d){
        if(!node) return;
        char temp;
        if(d == 'l'){
            res.push_back(node->val);
            if(node->left) dfs(node->left,d);
            if(node->right){
                // no left then it left boundary
                temp=node->left?'-':d;
                dfs(node->right,temp);
            }
        } 
        else if(d=='r'){
            if(node->left){
                temp = node->right?'-':d;
                dfs(node->left,temp);
            }
            if(node->right) dfs(node->right,d);
            res.push_back(node->val);
        }
        else{
            if(!node->left && !node->right) res.push_back(node->val);
            dfs(node->left,d);
            dfs(node->right,d);
        }
    }
};