#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int array[],int n)
{
    int j=0;
    for (int i = 1; i < n; i++)
    {
        j=i-1;
        int key=array[i];
        while (j>=0 && array[j]>key)
        {
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;
        
    }
    
}
int main(){
    int array[]={12,11,13,5,6};
    insertion_sort(array,sizeof(array)/sizeof(array[0]));
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i];
    }
    
    return 0;
}