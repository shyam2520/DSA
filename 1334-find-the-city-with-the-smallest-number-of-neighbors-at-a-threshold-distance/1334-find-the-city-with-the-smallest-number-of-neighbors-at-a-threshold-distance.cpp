class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // floyd warshall algorithm
        vector<vector<int>> adjMat(n,vector<int>(n,1e9));
        int res=n,city=n;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int cost=edge[2]; 
            adjMat[u][v]=adjMat[v][u]=cost;
        }
        for(int i=0;i<n;i++) adjMat[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    // if(adjMat[i][k]!=1e9 && adjMat[k][j]!=1e9){
                        adjMat[i][j]=min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
                    // }
                }
            }
        }
        
        int cnt;
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                // cout<<adjMat[i][j]<<" ";
                // if(i==j) continue;
                if(adjMat[i][j]>0 && adjMat[i][j]<=distanceThreshold) cnt++;
            }
            // cout<<cnt<<endl;
            if(cnt<=res){
                res=cnt;
                city=i;
            } 
        } 
        return city;
    }
};