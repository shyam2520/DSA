#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data ;
    Node* left;
    Node* right;
}*root;
Node* getnode(){
    Node* newnode=new Node;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void create(){
    int left, right ;
    queue<Node*>  address;
    cout<<"enter root node value"<<endl;
    root=getnode();
    cin>>root->data;
    address.push(root);
    while(!address.empty())
    {
        Node* p=address.front();
        address.pop();
        cout<<"enter the value of left child \n ";
        cin>>left;
        if(left!=-1){
            Node* leftnode=getnode();
            address.push(leftnode);
            p->left=leftnode;
            leftnode->data=left;
        }
        cout<<"enter the value of right child \n";
        cin>>right;
        if(right!=-1){
            Node* rightnode=getnode();
            address.push(rightnode);
            p->right=rightnode;
            rightnode->data=right;
        }
    }


}
void infix(Node* head){
    if(head)
{    infix(head->left);
    cout<<head->data;
    infix(head->right);}
}
void preorder(Node* head){
    stack<Node*> address;
    while(head || !address.empty())
    {
        if(head!=NULL)
        {cout<<head->data;
        address.push(head);
        head=head->left;}
        else if(head==NULL){
            head=address.top();
            address.pop();
            head=head->right;
        }
    }

}
void inorder(Node* head){
    stack<Node*> address;
    while(head || !address.empty())
    {if(head){
        address.push(head);
        head=head->left;
    }
    else if (head==NULL){
        head=address.top();
        address.pop();
        cout<<head->data;
        head=head->right;
    }
    }
}
void postorder(Node* whead){

}
int main(){
    create();
    infix(root);
    preorder(root);
    cout<<"\n inorder traversal \n";
    inorder(root);
    return 0;
}