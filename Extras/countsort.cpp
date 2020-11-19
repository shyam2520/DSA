#include<bits/stdc++.h>
using namespace std;
int main(){
    int array[]={2,5,3,3,1,1,1,7,9};
    int size=sizeof(array)/sizeof(array[0]);
    int max=*max_element(array,array+size);
    int countarray[max+1];
    for (int i = 0; i < max+1; i++)
    {
        countarray[i]=0;
    }
    for (int  i = 0; i < size; i++)
    {
        countarray[array[i]]++;
    }
    int i=0,j=0;
    while(i<max+1)
    {
        if(countarray[i]>0){
            
            array[j]=i;
            j++;
            countarray[i]--;
        }
        else{
            i++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout<<array[i];
        /* code */
    }
    
    
}