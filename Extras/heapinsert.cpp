#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int parent=i/2;
    if (arr[parent]<0){
        return ;
    }
    if(arr[i]>arr[parent])
    {
        swap(arr[parent],arr[i]);
        heapify(arr,n,parent);

    }
        // heapify(arr,n,parent);

}
void print(int arr[],int n){
    int i=0;
    while(i<n){
        cout<<arr[i];
        i++;
    }
}

void insert(int arr[],int& n,int key)
{
    n=n+1;
    arr[n-1]=key;
    heapify(arr,n,n-1);
}
int main(){
    int arr[]={10, 5, 3, 2, 4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"enter new value to be insert";
    int key=6;
    insert(arr,n,key);
    print(arr,n);

    return 0;
}