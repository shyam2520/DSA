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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q; 
        q.push(root); 
        TreeNode *node = NULL;
        int n=0; 
        vector<vector<int>> res;
        while(q.size()){
            n=q.size(); 
            vector<int> t;
            for(int i=0;i<n;i++){
                node = q.front(); 
                t.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left); 
                if(node->right) q.push(node->right);
            }
            res.push_back(t);
        }

        return res;
    }
};