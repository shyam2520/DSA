#include<bits/stdc++.h>
using namespace std;
void shellsort(int array[],int n){
    for (int gap = n/2; gap >=1 ; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp=array[i];
            int j=i-gap;
            while (j>=0 && array[j]>temp)
            {
                array[j+gap]=array[j];
                j=j-gap;
            }
            array[j+gap]=temp;
        }
        
    }
    
}
int main(){
    int array[]={12, 34, 54, 2,3};
    shellsort(array,sizeof(array)/sizeof(array[0]));    
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<endl;
    }
    
    return 0;
}