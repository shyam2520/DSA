#include<bits/stdc++.h>
using namespace std;
void insertion(int array[],int size){
    int j;
    for (int  i = 1; i < size; i++)
    {
        j=i;
        int temp=array[j];
        while(j>0 && temp<array[j-1])
        {
            array[j]=array[j-1];
            j--;
        }
        array[j]=temp;
        
    }
}
void selectionsort(int arr[],int size){
    int i,j,k;
    for (int  i = 0; i < size-1; i++)
    {
        for (j=k=i ; k < size; k++)
        {
            if(arr[j]>arr[k])
            {
                j=k;
            }

        }
        swap(arr[i],arr[j]);
        
        /* code */
    }
    
}
int main()
{
    int a[]={10,9,8,7,6,4,3,2,1};
    // for (int i = 0; i < 9-1; i++)
    // {
    //     for(int j=0;j<9-i-1;j++)
    //     {
    //         if(a[j]>a[j+1])
    //         {
    //             swap(a[j],a[j+1]);
    //         }
    //     }
    // }
    selectionsort(a,9);
    // insertion(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i];
    }
    
}