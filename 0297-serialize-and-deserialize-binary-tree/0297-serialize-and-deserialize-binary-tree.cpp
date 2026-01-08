/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // we will do level order traversal make it to string 
        // 1. we will push each node left & right to queue
        // 2. we will push NULL values also till the leaf node
        if(!root) return "";
        queue<TreeNode*> q; 
        q.push(root); 
        string res = "";
        bool not_null=true;
        while(q.size() && not_null){
            int n = q.size();
            not_null = false; 
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();

                res+=top?to_string(top->val)+",":"null,";
                if(top){
                    if(top->left || top->right) not_null=true;
                    q.push(top->left);
                    q.push(top->right);
                }
            }
        }
        res.pop_back();
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string temp;
        // vector<string> tempres;
        vector<TreeNode*> nodes;
        while(std::getline(ss,temp,',')){
            if(temp=="null") nodes.push_back(NULL);
            else {
                nodes.push_back(new TreeNode(stoi(temp)));
            }
        }

        if(!nodes.size()) return {};
        TreeNode* root = nodes.front();
        queue<TreeNode*> q; 
        q.push(root);
        for(int i=1;i<nodes.size();i++){
            q.front()->left=nodes[i];
            if(nodes[i]){
                q.push(nodes[i]);
            }
            i++; 
            if(i<nodes.size()){
                q.front()->right = nodes[i]; 
                if(nodes[i]) q.push(nodes[i]);
            }
            q.pop();
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));