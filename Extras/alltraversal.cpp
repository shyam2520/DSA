#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
}*root;
Node* getnode(){
    Node* newnode=new Node;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void create(){
    int left,right;
    queue<Node*> address;
    cout<<"Enter the root node";
    root=getnode();
    cin>>root->data;
    address.push(root);
    // looping starts 
    while(!address.empty())
{
    Node* p=address.front();
    address.pop();
    cout<<"enter left child value";
    cin>>left;
    if(left!=-1){
        Node* left_node=getnode();
        address.push(left_node);
        p->left=left_node;
        left_node->data=left;
    }
    cout<<"enter right child node";
    cin>>right;
    if(right!=-1){
        Node* right_child=getnode();
        p->right=right_child;
        address.push(right_child);
        right_child->data=right;
    }
}
}
void preorder(Node* head){
    if(head)
    {cout<<head->data;
    preorder(head->left);
    preorder(head->right);
}
}
void postorder(Node* pre){
    if(pre)
    {postorder(pre->left);
    postorder(pre->right);
    cout<<pre->data;}
}
void inorder(Node* first){
    if(first)
    {inorder(first->left);
    cout<<first->data;
    inorder(first->right);}
}
int main(){
    create();
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);

    return 0;
}