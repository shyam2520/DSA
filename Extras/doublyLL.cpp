#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
}*head=NULL,*rear=NULL;
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert(){
    Node* temp=getnode();
    cin>>temp->data;
    if(head==NULL){
       head=temp;
       head->next=NULL;
       head->prev=NULL;
       rear=head; 
    }
    else{
        temp->next=rear->next;
        temp->prev=rear;
        rear->next=temp;
        rear=temp;
    }
}
void display(Node* first){
    Node* displaydata=first;
    while(displaydata!=NULL){
        cout<<displaydata->data;
        displaydata=displaydata->next;
    }
}
void reversedisplay(Node* reard){
    Node* displaydata=reard;
    while(displaydata!=NULL)
    {
        cout<<displaydata->data;
        displaydata=displaydata->prev;
    }
}
void midinsert(int pos,int x){
    Node* modify = head;
    Node* temp=getnode();
    temp->data=x;
    if( pos==0){
        if( head==NULL){
             head=temp;
             head->next=NULL;
            head->prev=NULL;
            rear=head; 
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            modify=modify->next;
        }
        temp->next=modify->next;
        modify->next->prev=temp;
        temp->prev=modify;
        modify->next=temp;
    }
}
void middelete(int pos)
{
    Node* modify=head;
    if(pos==1)
    {
        if(modify->next==NULL){
            delete(modify);
            head=NULL;
            rear=head;
        }
        else{
            modify=head;
            delete(head);
            head=modify->next;
            head->prev=NULL;
        }

    }    
    else{
        for(int i=0;i<pos-1;i++){
            modify=modify->next;
        }
        cout<<modify->data<<endl;    
       
        if(modify->next==NULL){
            cout<<"check";
            Node* previous=modify->prev;
            previous->next=modify->next;
            delete(modify);
            rear=previous;
        }
         else if(modify!=NULL )
        {
        Node* previous=modify->prev;
        Node* future=modify->next;
        previous->next=future;
        future->prev=previous;
        delete(modify);
        }
    }
}

int main(){
    int n; 
    cout<<"enter the size of linked list ";
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    midinsert(3,8);
    midinsert(0,7);
    cout<<"forward display\n";
    display(head);
    cout<<"\n";
    middelete(3);
    middelete(1);
    middelete(4);
    cout<<endl;
    cout<<"reversed display";
    reversedisplay(rear);
    return 0;
}