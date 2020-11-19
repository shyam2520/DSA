#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* prev;
    Node* next;
}*head=NULL,*last=NULL;
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert(){
    Node* temp=getnode();
    cin>>temp->data;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
        head->prev=head;
        last=head;
    }
    else{
        temp->next=last->next;
        // rear->prev=temp;
        last->next=temp;
        temp->prev=last;
        last=temp;
        head->prev=temp;
    }
}
void display(Node* first)
{
    do{
        cout<<first->data;
        first=first ->next;
    }while(first!=head);
}
void rdisplay(Node* rear){
    do{
        cout<<rear->data;
        rear=rear->prev;
    }while(rear!=last);
}
void midinsert(int pos,int data){
    Node* temp=getnode();
    temp->data=data;
    Node* modify=head;
    if(pos==0){
        if(head==NULL){
            head=temp;
            head->next=head;
            head->prev=head;
            last=head;
        }
        else{
            temp->next=head;
            temp->prev=head->prev;
            head->prev->next=temp;
            head->prev=temp;
            head=temp;
        }

    }
    else{
        for(int i=0;i<pos-1;i++){
            modify=modify->next;
        }
        temp->next=modify->next;
        temp->prev=modify;
        modify->next->prev=temp;
        modify->next=temp;

    }

}
void middelete(int pos){
    Node* modify=head;
    // cout<<"called";
    if(pos==1){
        if(head->next==head){
            delete(head);
            head==NULL;
            cout<<"head called";
            last=head;
        }
        else{
            cout<<"called";
            head->next->prev=head->prev;
            head->prev->next=head->next;
            delete(head);
            head=modify->next;
        }
    }
    else{
        for(int i=0;i<pos-1;i++){
            modify=modify->next;
        }
        if(modify->next==head){
            modify->prev->next=modify->next;
            modify->next->prev=modify->prev;
            last=modify->prev;
            delete(modify);
        }
        else if(modify!=NULL){
            modify->prev->next=modify->next;
            modify->next->prev=modify->prev;
            delete(modify);
        }
    }
}
int main(){
    cout<<"enter the size";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
        insert();
    midinsert(0,7);
    midinsert(3,8);
    cout<<"\n forward display";
    display(head);
    middelete(1);
    middelete(3);
    middelete(4);
    cout<<"\n reverse display";
    rdisplay(last);
    
    return 0;
}