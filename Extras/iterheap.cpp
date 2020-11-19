#include<bits/stdc++.h>
using namespace std;
void insert(int a[],int arr_size,int key)
{
    int i=arr_size;
    a[i]=key;
    int temp=a[i];
    while (i>1 && temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
    // arr_size++;
    
}
int main(){
    int arr[]={0,10},key,count=0,arr_size=2;
    cout<<"enter the count";
    cin>>count;
        for (int  i = 0; i < count; i++)
    {
        cout<<"enter the new value";
        cin>>key;
        insert(arr,arr_size,key);
    }  

    return 0;
}