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
    vector<int> sol;
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        dfs(root,0);
        return sol;
    }

    void dfs(TreeNode* root,int idx){
        if(!root) return ;

        if(idx+1>sol.size()) sol.push_back(root->val);
        else if(sol[idx]<root->val) sol[idx]=root->val;
        

        dfs(root->left,idx+1);
        dfs(root->right,idx+1);
        // dfs(root->left,)
    }
};