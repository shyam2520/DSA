class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // bfs starting from 1  to [curr + 1, min(curr + 6, n2)]
        // convert value to indices (val-1)%n & (val-1)/n 
        // if s/l update the position and move push to queue 
        int n = board.size();
        queue<int> q;
        q.push(1);
        vector<bool> visited(n*n,false);
        visited[1]=true;
        int level=0;
        while(q.size()){
            int qs = q.size();
            for(int i=0;i<qs;i++){
                int curr = q.front();
                q.pop();
                for(int i = curr+1;i<=min(curr + 6, n*n);i++){
                    // 4
                    int row = (i-1)/n; // 1 
                    int col = (i-1)%n; // 1%2
                    row =(n-1)-row; // 2 -1 =1
                    if((row%2)!=((n-1)%2)) col = (n-1) -col;

                    int next = i;
                    if(board[row][col]!=-1){
                        next=board[row][col];
                    }
                    if(next==n*n) return level+1;
                    if(visited[next]==true) continue;
                    visited[next]=true;
                    q.push(next);
                    // cout<<i<<" "<<row<<","<<col<<endl;
                    // if(board[row][col]==-1){
                    //     visited[i]=true;
                    //     q.push(i);
                    // }
                    // else{
                    //     int newpos = board[row][col];
                    //     if(newpos==n*n) return level+1;
                    //     if(!visited[newpos]){
                    //         cout<<"newpost"<<" "<<newpos<<endl;
                    //         visited[newpos]=true;
                    //         q.push(newpos);
                    //     }                 
                    // }

                }
            }
            level++;
        }
        return -1;
    }
};