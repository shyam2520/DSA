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
    int postidx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postidx = postorder.size()-1; 
        return genTree(inorder,postorder,0,inorder.size()-1);
    }

    int findInidx(int curr_ele,vector<int>& inorder,int s,int e){
        for(int i=s;i<=e;i++){
            if(inorder[i]==curr_ele) return i;
        }
        return -1;
    }

    TreeNode* genTree(vector<int>& inorder,vector<int>& postorder,int s,int e){
        if(s>e) return NULL; 
        if(s==e) return new TreeNode(postorder[postidx--]);
        int curr_ele = postorder[postidx--]; 
        TreeNode* node = new TreeNode(curr_ele);
        int inidx = findInidx(curr_ele,inorder,s,e);
        if(inidx==-1) return NULL; 
        node->right = genTree(inorder,postorder,inidx+1,e);
        node->left = genTree(inorder,postorder,s,inidx-1); 
        return node;
    }
};