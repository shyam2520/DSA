#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
}*start=NULL,*finish=NULL;
Node* getnode(){
    Node* newnode=new Node;
    newnode->next=NULL;
    return newnode;
}
void insert(){
    Node* temp=getnode();
    cin>>temp->data;
    if(start==NULL)
    {
        start=temp;
        finish=start;
    }
    else{
        finish->next=temp;
        finish=temp;

    }
}
void checkloop(Node* beg){
    Node* p,*q;
    p=beg;
    q=beg;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:q=NULL;
    }while((p&&q) && (p !=q) );
    if(p==q){
        cout<<"TRUE ";
    }
    else{
        cout<<"FALSE";
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        insert();
    }
    finish->next=start->next->next;
    checkloop(start);
    return 0; 
}