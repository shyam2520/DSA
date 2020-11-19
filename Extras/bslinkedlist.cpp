#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
Node* first=NULL;
Node* last=NULL;
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    return newnode;
}
void insert(){
    
    Node* newnode=getnode();

    if(newnode==NULL){
        cout<<"system out of mem";
    }
    else if (first==NULL){
        first=newnode;
        last=first;
        cin>>first->data;
    }
    else{
    cin>>newnode->data;
    last->next=newnode;
    last=newnode;
    }
}
void sorted(Node* vfirst)
{
    int swapped;
    Node* end=NULL;
    Node*  start=vfirst;
    do{
        // cout<<"start";
        swapped=0;
        start=vfirst;
        while (start->next!=end)
        {
            if(start->data>start->next->data){
                int temp=start->data;
                start->data=start->next->data;
                start->next->data=temp;
                swapped=1;
                cout<<"done ";
                // start=start->next;
            }
            start=start->next;
        }
        end=start;
        
        
    }while(swapped);

}
void duplicates(Node* starting){
    Node* prev=starting;
    Node* current=starting->next;
    while(current!=NULL){
        if(prev->data==current->data){
            prev->next=current->next;
            delete(current);
            current=prev->next;
        }
        else{
        prev=current;
        current=current->next;
        }
    }
}
void reverse(Node* head){
    Node* current=NULL;
    Node* prev=NULL;
    while(head!=NULL){
        prev=current;
        current=head;
        head=head->next;
        current->next=prev;
    }
    first=current;
}
void rreverse(Node* prev,Node* head){
    if(head!=NULL)
    {
        rreverse(head,head->next);
        head->next=prev;
    }
    else{
        first=prev;
    }
}

int main(){
    cout<<"how many elements to insert";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    // sorted(first);
    // duplicates(first);
    rreverse(NULL,first);
    cout<<"display\n";
    Node* display=first;
    while(display!=NULL){
        cout<<display->data<<endl;
        display=display->next;
    }
    return 0;
}