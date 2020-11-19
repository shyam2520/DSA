#include<iostream>
using namespace std;

int main()
{

    cout<<"Enter array size ";
    int n;
    cin>>n;
    int a[n+10]; 
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    int length=sizeof(a)/sizeof(a[0]);
    cout<<"enter the values to append the element";
    int appender;
    cin>>appender;
    a[n]=appender;
    for(int i=0;i<=length;i++){
        cout<<a[i];
    }
    // cout<<"enter the index and the element to enter ";
    // int index,value;
    // cin>>index>>value;
    // if (index==length)
    // {
    //     a[index]=value;
    // }
    // else{
    //     for(int i=length;i>index;i++){
    //         a[i+1]=a[i];
    //     }
    //     a[index]=value;
    // }

    //  for(int i=0;i<length;i++){
    //     cout<<a[i];
    // }

    
    
    return 0;
}