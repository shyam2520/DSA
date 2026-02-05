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
    map<int,vector<pair<int,int>>> dict; //col->{{row,val}}
    
    void dfs(TreeNode* node,int rowidx,int colidx){
        if(!node) return ;
        // if(!dict.count(colidx)) dict[colidx]=
        dict[colidx].push_back({rowidx,node->val});
        dfs(node->left,rowidx+1,colidx-1);
        dfs(node->right,rowidx+1,colidx+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // 0 -> {{1},{5,6}}
        // 0,0 -> 1,-1, 1,1 
        dfs(root,0,0);
        // using dictionary to get result
        vector<vector<int>> ans;
        for(auto& i:dict){ 
            // (2,5),(2,6)
            vector<int> temp;
            vector<pair<int,int>> res = i.second; 
            sort(begin(res),end(res));
            for(auto& val:res) temp.push_back(val.second);
            ans.push_back(temp);
        }
        return ans;
    }
};