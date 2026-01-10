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
class compare{
    public: 
    bool operator()(TreeNode* a,TreeNode* b){
        return a->val<b->val;
    }
};

class Solution {
public:
    vector<TreeNode*> inorderarr;
    void recoverTree(TreeNode* root) {
        // 1. inorder traversal store nodes 
        // 2. find two values which are in wrong place 
        // 3. swap the data 
        inorder(root);
        vector<TreeNode*> cpy=inorderarr;
        sort(inorderarr.begin(),inorderarr.end(),compare());
        TreeNode* temp1=NULL,*temp2=NULL;
        for(int i=0;i<inorderarr.size();i++){
            if(inorderarr[i]->val!=cpy[i]->val){
                if(!temp1) temp1 = cpy[i];
                else temp2=cpy[i];
                // swap(inorderarr[i]->val,cpy[i]->val);
            }
        }
        int temp = temp1->val;
        temp1->val = temp2->val;
        temp2->val = temp;
    }

    void inorder(TreeNode* node){
        if(!node) return ;
        inorder(node->left);
        inorderarr.push_back(node);
        inorder(node->right); 
    }
};