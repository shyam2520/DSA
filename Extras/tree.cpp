#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
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
    int left,right;
    queue<Node*> address;
    cout<<"enter the root";
    root=getnode();
    cin>>root->data;
    cout<<root; 
    address.push(root);
    
    //loop this area
    while(!address.empty())
    {Node* p=address.front();
    address.pop();
    cout<<"enter left subchild";
    cin>>left;
    if(left!=-1)
    {
        Node* leftnode=getnode();
        address.push(leftnode);
        leftnode->data=left;
        p->left=leftnode;
    }
    cout<<"enter the right value";
    cin>>right;
    if(right!=-1){
        Node* rightnode=getnode();
        address.push(rightnode);
        rightnode->data=right;
        p->right=rightnode;
    }}
}
void preorder(Node* rootd){
  if(rootd)
 {   cout<<rootd->data;
    preorder(rootd->left);
    preorder(rootd->right);}
}
int main(){
    create();
    preorder(root);
    return 0;
}