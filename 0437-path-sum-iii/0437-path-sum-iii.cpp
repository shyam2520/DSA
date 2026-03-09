/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long  val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long  x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long  x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long  res=0;
    int  pathSum(TreeNode* root, long long  targetSum) {
        unordered_map<long long ,long long > dict; // sum-> cnt; 
        // dict[0]=1;
        dfs(root,targetSum,0,dict);
        return res;
    }

    void dfs(TreeNode* node,long long & targetSum,long long  sum,unordered_map<long long ,long long > dict){
        if(!node) return ;
        sum+=node->val;
        if(sum==targetSum) res++;
        if(dict[sum-targetSum]!=0){
            res+=dict[sum-targetSum];
        } 
        dict[sum]++;
        dfs(node->left,targetSum,sum,dict);
        dfs(node->right,targetSum,sum,dict);
    }
};