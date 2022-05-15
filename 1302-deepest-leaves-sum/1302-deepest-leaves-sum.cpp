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
    int res=0,maxlen=0;
public:
    int deepestLeavesSum(TreeNode* root) {
         search(root,0);
        return res;
    }
    void search(TreeNode* root,int len)
    {
         if(!root) return ;
         if(!root->left && !root->right)
         {
            if(maxlen<len)
            {
                res=root->val;
                maxlen=len;
            }
            else if(maxlen==len) res+=root->val;
            return ;
        }
        search(root->left,len+1);
        search(root->right,len+1);
    }
};