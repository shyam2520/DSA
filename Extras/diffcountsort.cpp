#include<bits/stdc++.h>
using namespace std;
void countsort(int array[])
{
    int count[10]={0};
    for(int i=0;i<7;i++){
        count[array[i]]++;
    }
    int structred[10]={0};
    for (int i = 1; i <=7; i++)
    {
        count[i]+=count[i-1];
    }
    for (int i = 0; i <7; i++)
    {
        structred[count[array[i]]-1]=array[i];
        count[array[i]]--;
    }
    for (int i = 0; i <10; i++)
    {
        cout<<structred[i];
    }
    
    
    
    
    

}
int main(){
    int array[]={1,4,1,2,7,5,2};
    countsort(array);

    return 0;
}