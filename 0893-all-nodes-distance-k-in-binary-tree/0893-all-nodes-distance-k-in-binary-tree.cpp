/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        queue<pair<TreeNode*,TreeNode*>> q;
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* temp,*parent_node;
        q.push({root,NULL});
        int s;
        while(q.size()){
            s=q.size();
            for(int i=0;i<s;i++){
                temp=q.front().first;
                parent_node=q.front().second;
                q.pop();
                parent[temp]=parent_node;
                if(temp->left) q.push({temp->left,temp});
                if(temp->right) q.push({temp->right,temp});
            }
        }
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> d;
        int level =0;
        d.push(target);
        while(!d.empty() && level!=k){
            s=d.size();
            for(int i=0;i<s;i++){
                temp=d.front();
                d.pop();
                visited[temp]=true;
                if(parent[temp] && !visited[parent[temp]]) d.push(parent[temp]);
                if(temp->left && !visited[temp->left]) d.push(temp->left);
                if(temp->right && !visited[temp->right]) d.push(temp->right);
            }
            level++;
        }
        vector<int> res;
        while(d.size()){
            res.push_back(d.front()->val);
            d.pop();
        }

        return res;
    }
};