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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        int size,max_val;
        TreeNode* t=NULL;
        q.push(root);
        while(!q.empty()){
            size=q.size();
            max_val = INT_MIN;
            for(int i=0;i<size;i++){
                t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                max_val=max(max_val,t->val);            
            }
            res.push_back(max_val);

        }

        return res;
        
    }
};