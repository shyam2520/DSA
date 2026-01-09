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
class BSTIterator {
public:
    // 1. push all left nodes of the tree into strack 
    // 2. when popping move to right push to stack and repat step one 
    stack<TreeNode*> stack;
    TreeNode* node; 
    BSTIterator(TreeNode* root) {
        node = root; 
        while(node){
            stack.push(node); 
            node=node->left;
        }
    }
    
    int next(){
        TreeNode* node = stack.top();
        stack.pop();
        int res = node->val;
        node=node->right; 
        while(node){
            stack.push(node);
            node=node->left;
        }
        return res;
    }
    
    bool hasNext() {
        return stack.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */