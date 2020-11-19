#include<iostream>
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
    Node* display=first;
    while(display!=NULL)
    {
        cout<<display->data;
        display=display->next;
    }
    cout<<"pop";
    Node* deleted=new Node;
    Node* temp;
    deleted=first;
    while(deleted!=last){
        temp=deleted;
        deleted=deleted->next;
    }
    cout<<deleted->data<<" is gonna get deleted";
    delete(deleted);
    temp->next=NULL;
    last=temp;
    cout<<last->data<<"is the new last";

    return  0;

}