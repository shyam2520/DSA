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
    using treeIdx = pair<TreeNode*,long long>;
    long long mod = INT_MAX;
    int widthOfBinaryTree(TreeNode* root) {
        // 1. consider each node as row in 2D matrix 
        // 2. left node idx = 2*pidx, right node idx = 2*pidx+1;
        queue<treeIdx> q; 
        q.push({root,0}); 
        long long res = 0,n;
        // TreeNode *top; 
        while(q.size()){
            n=q.size();
            long long fidx = q.front().second;
            for(int i=0;i<n;i++){
                TreeNode* top= q.front().first;
                long long idx = q.front().second;
                res=max(abs(fidx-idx)+1,res);
                q.pop();
                idx = idx-fidx;
                if(top->left) q.push({top->left,(2*idx)});
                if(top->right) q.push({top->right,((2*idx)+1)});
            }
        }
        return res;
    }
};