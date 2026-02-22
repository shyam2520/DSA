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
        // return "";
        // level order travrsel till last flag is true 
        // push null only for existing noes
        queue<TreeNode*> q;
        if(!root) return "";
        q.push(root);
        string res="";
        bool flag = true;
        while(q.size() && flag){
            flag=false;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* front = q.front();
                q.pop();
                if(!front){
                    res+="N,";
                    continue;
                } 
                else res+=to_string(front->val)+",";
                q.push(front->left);
                q.push(front->right);
                if(front->left || front->right){
                    flag=true;
                } 
            }
        }
        res.pop_back();
        // cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // push the first value into queue every 2 indices would be the left & right 
        // if null node don't push to queue
        if(data=="") return NULL;
        stringstream ss(data);
        string temp;
        queue<TreeNode*> q; 
        vector<TreeNode*> nodes;
        while(std::getline(ss,temp,',')){
            if(temp=="N") nodes.push_back(NULL);
            else nodes.push_back(new TreeNode(stoi(temp)));
        }
        
        
        TreeNode* root = nodes.front();
        q.push(root);
        int i=1;
        TreeNode* curr;
        while(i<nodes.size()){
            TreeNode* front = q.front();
            q.pop();
            // left
            if(i<nodes.size()){
                curr=nodes[i++];
                front->left =curr;
                if(curr) q.push(curr);
            }
            // right
            if(i<nodes.size()){
                curr=nodes[i++];
                front->right=curr;
                if(curr) q.push(curr);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));