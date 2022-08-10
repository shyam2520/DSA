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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bin(nums,0,nums.size()-1);
    }
    
    TreeNode* bin(vector<int>& nums,int l,int r)
    {
        if(l>r) return NULL;
        if(l==r) return new TreeNode(nums[l]);
        
        int mid=l+(r-l)/2;
        TreeNode* node= new TreeNode(nums[mid]);
        node->left=bin(nums,l,mid-1);

        node->right=bin(nums,mid+1,r);
        return node;
    }
};