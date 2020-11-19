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
    int visited[8]={0};
    int i=1;
    visited[i]=1;
    queue<int> nodes;
    cout<<i;
    nodes.push(i);
    while (!nodes.empty())
    {
        int current=nodes.front();
        nodes.pop();
        for (int adjacent= 1; adjacent <=7; adjacent++)
        {
            if(array[current][adjacent]==1 && visited[adjacent]==0)
            {
                visited[adjacent]=1;
                cout<<adjacent;
                nodes.push(adjacent);

            }
        }
        

    }
    
    return 0;
}