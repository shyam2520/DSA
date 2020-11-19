#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    return newnode;
}
int main(){
    int a[]={1,2,3,4,5};
    Node* first=getnode();
    first->data=a[0];
    Node* last=first;
    for(int i=1;i<5;i++){
        Node* temp=getnode();
        last->next=temp;
        last=temp;
    }
    cout<<"Print\n";
    Node* display=first;
    while(display!=NULL)
    {
        cout<<display->data<<"\n";
        display=display->next;

    }
    int count=0;
    display=first;
    while(display!=NULL){
        count++;
        display=display->next;
    }
    cout<<count;


    return 0;
}