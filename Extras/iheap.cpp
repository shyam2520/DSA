#include<bits/stdc++.h>
using namespace std;
void heapify(int array[],int size,int i){
    int parent=i/2;
    if(array[i]>array[parent])
    {
        swap(array[parent],array[i]);
        cout<<array[parent]<<array[i];
        heapify(array,size,parent);
    }

}
void insert(int array[],int& size,int key){
    size+=1;
    array[size-1]=key;
    heapify(array,size,size-1);
    

}
int main(){
    int array[]={11};
    int size,key;
    size=sizeof(array)/sizeof(array[0]);
    int count;
    cout<< "enter the count";
    cin>>count;
    int j=0;
    while(j<count)
    {
        cout<<"enter the key";
        cin>>key;
        insert(array,size,key);
        j++;
    }
        
}