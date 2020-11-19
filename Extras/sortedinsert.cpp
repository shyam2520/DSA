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
void sortedinsert(Node* startingpoint, int datav){
    Node* prev=NULL;
    Node* tp=startingpoint;
    Node* newdata=getnode();
    newdata->data=datav;
    while(tp!=NULL&& tp->data<datav)
    {
            prev=tp;
            tp=tp->next;
    }
    prev->next=newdata;
    newdata->next=tp;
    
}
void deletevalue(Node* startpoint,int deletval){
    Node* temp=NULL;
    if(deletval==first->data){
        temp=first;
        first=first->next;
        delete(first);
    }
    else{
        while(startpoint!=NULL&& deletval!=startpoint->data){
            temp=startpoint;
            startpoint=startpoint->next;
        }
        temp->next=startpoint->next;
        delete(startpoint);
    }
}
int main(){
    cout<<"how many elements to insert";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    sortedinsert(first,4);
    deletevalue(first,3);
    cout<<"display\n";
    Node* display=first;
    while(display!=NULL){
        cout<<display->data<<endl;
        display=display->next;
    }
    return 0;
}