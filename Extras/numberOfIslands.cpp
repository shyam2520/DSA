#include<bits/stdc++.h>
using namespace std;
   int getAdjacentIslands(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j>grid[i].size()-1|| i>grid.size()-1 || j<0 ||grid[i][j]=='0'){
            return 0;   
        }
        cout<<i<<j;
        grid[i][j]='0';
        getAdjacentIslands(grid,i+1,j);
        getAdjacentIslands(grid,i-1,j);
        getAdjacentIslands(grid,i,j+1);
        getAdjacentIslands(grid,i,j-1);
        return 1;
    }
 int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
         for(int j=0;j<grid[i].size();j++)
         {
             // cout<<grid[j].size();
             if(grid[i][j]=='1'){
                 if(i==0 || j==0  || i==grid[i].size()-1 || j==grid[j].size()-1)
                 {
                     count+=getAdjacentIslands(grid,i,j);
                 }
             }
         }
         // cout<<endl;
     }
        return count;
    }
 
int main()
{
    vector<vector<char> > grid 
    {
  {"1","1","0","0","0"},
  {"1","1","0","0","0"},
  {"0","0","1","0","0"},
  {"0","0","0","1","1"}
    };
    
    return 0;
}