#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
}*head=NULL,*rear=NULL;
Node* getnode(){
    Node* temp=new Node;
    temp->next=NULL;
    return temp ;
}
void insert(){
    Node* t=getnode();
    cin>>t->data;
    if(head==NULL)
    {
    head=getnode();
    head->data=t->data;
    head->next=head;   
      
    rear=head;
    }
    else{ 
         t->next=rear->next;
         rear->next=t;
         rear=t;
    }
}
void display(Node* f){
    Node* display=f;
    do{
        cout<<display->data<<endl;
        display=display->next;
    }while(display!=head);

}
void rdisplay(Node* f){
    static int flag=0;
    Node* display =f;
    if(display!=head||flag!=1)
    {
        flag=1;
        cout<<display->data<<endl;
        rdisplay(display->next);
    }
}
void dataInsert(int pos,int data)
{
    Node* t=getnode();
    t->data=data;
    if(pos==0){
        if(head==NULL){
            head=t;
            t->next=head;
            rear=head;
        }
        else{
            t->next=head;
            head= t;
            rear->next=t;
        }
    }
    else{
        Node* modify =head;
        for(int i=0;i<pos-1;i++){
            modify=modify->next;
        }
        t->next=modify->next;
        modify->next=t;
    }

}
void dataDelete(int pos){
    Node* deleteNode=head;
    if(pos==1){
        if(deleteNode->next==head)
        {
            delete(head);
            head=NULL;
        }
        else {
            rear->next=head->next;
            delete(head);
            head=rear->next;
        }
    }
    else{
        for(int i=0;i<pos-2;i++){
            deleteNode=deleteNode->next;
        }
        // if(deleteNode==NULL || deleteNode->next)
        Node* future=deleteNode->next;
        deleteNode->next=future->next;
        delete(future);

    }
}
int main(){
    int n;
    cout<<"enter the size ?";
    cin>>n;
    while(n>0){
        insert();
        n--;
    }
    dataInsert(0,7);
    dataInsert(3,8);
    cout<<"loop display";
    display(head);
    dataDelete(1);
    dataDelete(3);
    cout<<"\n recursive display";
    rdisplay(head);

    return  0;
}