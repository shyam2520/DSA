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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // i - [9,3,
         //    [9]   [15,20,7]
        // p - [3,9,20,15,7]
        // p [1,2,3,4,....20]
        // i [1,2,3,4,....20]

        // preidx for preord 
        // search preidx val in inorder 
        // split inorder to its lst & rst
         
        return tree(preorder,inorder,0,inorder.size()-1);

    }

    int search(vector<int>& in,int st,int end,int val){
        for(int i=st;i<=end;i++){
            if(in[i]==val) return i;
        }
        return -1;
    }

    TreeNode* tree(vector<int>& pre,vector<int>& in,int st,int end){
        if(st>end) return NULL;
        if(st==end){
            preidx++;
            return new TreeNode(in[st]);
        }
        // create node for preidx 
        TreeNode* node = new TreeNode(pre[preidx]);
        int idx=search(in,st,end,pre[preidx]);

        if(idx==-1) return NULL;
        preidx++;
        node->left=tree(pre,in,st,idx-1);
        node->right=tree(pre,in,idx+1,end);
        return node;
    }
};