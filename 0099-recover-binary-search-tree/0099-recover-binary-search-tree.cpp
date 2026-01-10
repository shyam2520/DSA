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
    vector<TreeNode*> inorder; 

    void inordertraversal(TreeNode* node){
        stack<TreeNode*> stk;
        // TreeNode* node = root; 
        while( stk.size() || node){
            if(node){
                while(node){
                    stk.push(node);
                    node=node->left;
                }
            }
            else{
                TreeNode* top = stk.top();
                stk.pop();
                node=top->right;
                inorder.push_back(top);
            }
        }
    }
    void recoverTree(TreeNode* root) {
        inordertraversal(root);
        TreeNode *temp1=NULL,*temp2=NULL; 
        int n = inorder.size();
        for(int i=0;i<n;i++){
            // compare with its next elements 
            if(i>0 && inorder[i-1]->val>inorder[i]->val)
            {
                    if(!temp1) temp1=inorder[i]; 
                    else temp2=inorder[i];
            }
            else if(i<n-1 && inorder[i]->val>inorder[i+1]->val){
                if(!temp1) temp1=inorder[i]; 
                else temp2=inorder[i];
            }

        }

        int temp = temp1->val; 
        temp1->val = temp2->val;
        temp2->val = temp;

    }
};