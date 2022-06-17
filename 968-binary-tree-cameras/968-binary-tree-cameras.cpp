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
    int has_cam=0;
    int needs_cam=1;
    int no_required=2;
    int count=0;
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root)==needs_cam?count+1:count;
    }
    int dfs(TreeNode* root)
    {
        if(!root) return no_required;
        if(!root->left && !root->right) return needs_cam;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==needs_cam||right==needs_cam)
        {
            count++;
            return has_cam;
        }
        else if(left==has_cam||right==has_cam) return no_required;
        return needs_cam;
    }
};