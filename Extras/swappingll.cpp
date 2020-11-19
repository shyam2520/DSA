#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    return newnode;
}
void display(Node* head)
{
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
}
void swap(Node* first,int x, int y )
{
    Node* currX,*prevX,*currY,*prevY;
    currX=first;
    currY=first;
    if(x==y)
    {
        return ;
    }
    while(currX && currX->data!=x){
        prevX=currX;
        currX=currX->next;
    }
    cout<<currX->data<<endl;
    while(currY&&currY->data!=y){
        prevY=currY;
        currY=currY->next;
    }
    cout<<currY->data<<endl;
    if(currY==NULL || currX==NULL){
        return ;
    }
    if(prevX==NULL)
    {
        first=currY;
    }
    else{
        prevX->next=currY;
    }
    if(prevY==NULL){
        first=currX;
    }
    else{
        prevY->next=currX;
    }
    Node* temp=currY->next;
    currY->next=currX->next;
    currX->next=temp;

}
int main(){
    int a[]={1,2,3,4,5};
    Node* first=getnode();
    first->data=a[0];
    Node* last=first;
    for(int i=1;i<5;i++){
        Node* temp=getnode();
        temp->data=a[i];
        last->next=temp;                                                            
        last=temp;
    }
    swap(first,3,5);
    display(first);
    return 0;

}