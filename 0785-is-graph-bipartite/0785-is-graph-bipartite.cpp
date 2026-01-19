class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size(); 
        vector<int> colors(nodes,-1); 
        for(int i=0;i<nodes;i++){
            if(colors[i]!=-1) continue; 
            else{
                bool res = dfs(graph,i,0,colors) || dfs(graph,i,1,colors);
                if(!res) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph,int idx, int color,vector<int>& colors){
        
        int new_colors = !color; 
        colors[idx]=color;
        for(auto& neigh:graph[idx]){
            if(colors[neigh]!=-1 && colors[neigh]==color) return false; 
            else{
                if(colors[neigh]!=-1) continue; 
                if(!dfs(graph,neigh,new_colors,colors)) return false;
            }
        }

        return true;

    }
};