#include<bits/stdc++.h>
using namespace std;
int main(){
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
    // cout<<"enter the starting node";
    int i=1;
    // cin>>i;
    int visited[8]={0};
    queue<int> node;
    visited[i]=1;
    cout<<i;
    node.push(i);
    while (!node.empty())
    {
        int row=node.front();
        node.pop();
        for (int column = 1; column <=7; column++)
        {
            if(array[row][column]==1 && visited[column] ==0)
            {
                visited[column]=1;
                cout<<column;
                node.push(column);
            }
        }
        
    }
    

    return 0;
}