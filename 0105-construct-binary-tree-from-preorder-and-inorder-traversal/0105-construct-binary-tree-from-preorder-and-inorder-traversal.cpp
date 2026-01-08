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
    int preidx=0; 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // 1. use the preidx to fill root, left , right 
        // 2. split inorder array based on the value inidx ->(0,inidx-1), (inidx+1, n);
        return genTree(preorder,inorder,0,inorder.size()-1);
    }

    int findIdx(vector<int>& inorder,int ele,int s,int e){
        for(int i=s;i<=e;i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }

    TreeNode* genTree(vector<int>& preorder,vector<int>& inorder,int l,int r)
    {
        if(l==r) {
            return new TreeNode(preorder[preidx++]);
        }

        if(l>r) return NULL;
        int node_val = preorder[preidx]; 
        
        //find the element in inorder and split nodes 
        int in_idx = findIdx(inorder,node_val,l,r);
        if(in_idx==-1) return NULL;
        preidx++;

        // 
        TreeNode* node = new TreeNode(inorder[in_idx]);
        node->left= genTree(preorder,inorder,l,in_idx-1);
        node->right = genTree(preorder,inorder,in_idx+1,r);
        return node;
    }
};