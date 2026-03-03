class Solution {
public:
    bool dfs(vector<int>& left,vector<int>& right,int ridx,vector<bool>& visited){
        if(ridx==-1) return true;
        if(visited[ridx]) return false; 
        visited[ridx]=true;
        return dfs(left,right,left[ridx],visited) && dfs(left,right,right[ridx],visited);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // find root node 
        // do dfs to find if its recursive 
        vector<bool> visited(n,false);
        vector<int> parent(n,-1);
        int root=0;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) parent[leftChild[i]]=i;
            if(rightChild[i]!=-1) parent[rightChild[i]]=i;
            // if(leftChild[i]==root || rightChild[i]==root) root=i;
        }
        for(int i=0;i<n;i++) if(parent[i]==-1) root=i;
        if(!dfs(leftChild,rightChild,root,visited)) return false;

        for(auto i:visited){
            // cout<<i<<endl;
            if(!i) return false;
        } 

        return true;
    }
};