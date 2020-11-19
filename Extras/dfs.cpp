#include<bits/stdc++.h>
using namespace std;
void dfs(int array[][8],int visited[],int i){
    if(visited[i]==0){
        cout<<i;
        visited[i]=1;
    
    for (int column= 1;column <=7; column++)
    {
        if(array[i][column]==1){
            dfs(array,visited,column);
        }
    }
    }
}
int main(){
    int visited[8]={0};
       int array[8][8]={
                    {0,0,0,0,0,0,0,0},
                    {0,0,1,1,1,0,0,0},
                    {0,1,0,1,0,0,0,0},
                    {0,1,1,0,1,0,0,0},
                    {0,1,0,1,0,1,0,0},
                    {0,0,0,1,1,0,1,1},
                    {0,0,0,0,0,1,0,0},
                    {0,0,0,0,0,1,0,0}               
                };
    dfs(array,visited,2);
    return 0;
}