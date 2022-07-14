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
    int preidx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preidx=0;
        // return new TreeNode(2);
        return buildTree(preorder,inorder,0,inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int l,int r)
    {
        if(l==r)
        {
            return new TreeNode(preorder[preidx++]);
        }
        if(l>r) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preidx]);
        int inidx=-1;
        for(int i=l;i<=r;i++)
        {
            if(inorder[i]==preorder[preidx])
            {
                inidx=i;
                break;
            }
        }
        
        if(inidx==-1) return NULL;
        preidx++;
        
        root->left=buildTree(preorder,inorder,l,inidx-1);
        root->right=buildTree(preorder,inorder,inidx+1,r);
        
        return root;
        
    
    }
    
};