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
    TreeNode *startAdress=NULL;
    void dfs(TreeNode* node,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>& dict,int& start)    
    {
        if(!node) return; 
        if(node->val==start) {
            startAdress=node; 
        }    
        dict[node]=parent;
        dfs(node->left,node,dict,start);
        dfs(node->right,node,dict,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> dict; 
        dfs(root,NULL,dict,start);
        // unordered_set<TreeNode*> visited;
        // bfs from startNode 
        // cout<<startAdress->val<<endl;
        queue<TreeNode*> q; 
        q.push(startAdress);
        int cnt = 0;
        unordered_set<TreeNode*> visited={startAdress};
        while(q.size()){
            int n = q.size(); 
            for(int i=0;i<n;i++){
                TreeNode* top = q.front(); 
                q.pop();
                if(top->left && visited.find(top->left)==visited.end()){
                    q.push(top->left);
                    visited.insert(top->left);
                }
                if(top->right && visited.find(top->right)==visited.end()){
                    q.push(top->right);
                    visited.insert(top->right);
                }
                if(dict[top] && visited.find(dict[top])==visited.end()){
                    q.push(dict[top]);
                    cout<<dict[top]->val<<endl;
                    visited.insert(dict[top]);
                }
            }
            if(q.size()){
                cout<<q.size()<<endl;
                cnt++;
            } 
        }
        return cnt;
    }
};