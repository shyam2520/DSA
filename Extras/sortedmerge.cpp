#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
Node* first=NULL,*second=NULL,*firstend=NULL,*secondend=NULL;
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    return newnode;
}
void finsert(){
   Node* temp=getnode();
    cin>>temp->data;
    if(first==NULL){
        first=temp;
        firstend=first;
    }
    else{
    firstend->next=temp;
    firstend=temp;
    }
}
void sinsert(){
    Node* temp=getnode();
    cin>>temp->data;
    if(second==NULL){
        second=temp;
        secondend=second;
    }
    else{
    secondend->next=temp;
    secondend=temp;
    }
}
Node* mergesort(Node* first,Node* second){
    Node* third=NULL,*last=NULL;
    while (first!=NULL && second!=NULL)
    {
        if(first->data<second->data){
            if(third==NULL){
                third=first;
                last=third;
            }
            else{
                last->next=first;
                last=first;
            }
            // last->next=NULL;
            first=first->next;
        }
        else{
            if(third==NULL){
                third=second;
                last=third;
            }
            else{
                last->next=second;
                last=second;
            }
        // last->next=NULL;
        second=second->next;
        }
    }  
        
    if(first==NULL)
    {
        last->next=second;
    }
    else{
        last->next=first;
    }
     return third;

}
int main()
{
    int m,n;
    cout<<"enter the size of two lists";
    cin>>m>>n;
    cout<<"enter the first list";
    for(int i=0;i<m;i++){
        finsert();
    }
    cout<<"enter the data of the second list";
      for(int i=0;i<n;i++){
        sinsert();
    }
    Node* display=mergesort(first,second);
    
    // cout<<firstend->next;
    while(display!=NULL)
    {
        cout<<display->data<<endl;
        display=display->next;
    }
    return 0;
}