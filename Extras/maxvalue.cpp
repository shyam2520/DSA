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
Node* tsearch(Node* p,int key )
{
    Node* first=p;
    // cout<<first->next->data<<"first data";
    Node* q=NULL;
    while(p)
    {
        if(p->data==key){
            q->next=p->next;
            p->next=first;
            first=p;
            return first;
        }
        q=p;
        p=p->next;
       
    }
     return NULL;

}
Node* insert(Node* startingpoint,int n,int key)
{
     Node* insertdata=getnode();
    insertdata->data=key;
    Node* first=startingpoint;
    if(n!=0)
    {
        for(int i=0;i<n-1;i++){
        startingpoint =startingpoint->next;
        }
        insertdata->next=startingpoint->next; 
        startingpoint->next=insertdata;
        return first;
    }
    else{
       
        insertdata->next=startingpoint;
        startingpoint=insertdata;
        return startingpoint;
    }

}
int main(){

    int min=INT_MAX;
    cout<<"enter the data of the elements\n";
    Node* first=getnode();
    int firstdata;
    cin>>firstdata;
    first->data=firstdata;
    Node* last=first;
    for(int i=0;i<4;i++){
        Node* temp=getnode();
        int a;
        cin>>a;
        temp->data=a;    
        first->next=temp;
        first=temp;
    }
    // last=(tsearch(last,3));
    // if(last){
    //     cout<<last<<"\n";
    // }
    // else{
    //     cout<<"Not found";
    // }
    last=insert(last,5,7);
      cout<<"displaying the data\n";
    while(last!=NULL){
        cout<<last->data<<"\n";
        last=last->next;
    }
    // cout<<min;
    return 0;
}