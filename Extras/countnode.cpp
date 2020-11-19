#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
}*root;
Node* getnode(){
    Node* newnode = new Node;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void create(){
    queue<Node*> address;
    cout<<"\n Enter the value of root ";
    root=getnode();
    cin>>root->data;
    address.push(root);
    while(!address.empty()){
        Node* p =address.front();
        address.pop();
        cout<<"Enter the left Node";
        int left,right;
        cin>>left;
        if(left!=-1){
            Node* leftnode=getnode();
            leftnode->data=left;
            address.push(leftnode);
            p->left=leftnode;
        }
           cout<<"Enter the right Node";
        // int left,right;
        cin>>right;
        if(right!=-1){
            Node* rightnode=getnode();
            rightnode->data=right;
            address.push(rightnode);
            p->right=rightnode;
        }

    }
}
void postorder(Node* root){
    stack<Node*> children,parent;
    Node* head=NULL;
    children.push(root);
    while(!children.empty()){
        head=children.top();
        children.pop();
        parent.push(head);
      
        if(head->left){
            children.push(head->left);
        }
          if(head->right)
        {
            children.push(head->right);
        }
    }
    while(!parent.empty())
    {
        cout<<parent.top()->data;
        parent.pop();
    }
}
int countnode(Node* root){
    if(root){
        int x=countnode(root->left);
        int y=countnode(root->right);
         return x+y+1;
    }
    return 0;
}
int height(Node* root){
    if(root){
        int leftsubtree=height(root->left);
        int rightsubtree=height(root->right);
        if(leftsubtree>rightsubtree)
        {
            return leftsubtree+1;
        }
        else {
            return rightsubtree+1;
        }

    }
    return 0;
}
int leftcount(Node* root){
    int x=0,y=0;
        if(root->left==NULL && root->right==NULL )
       {
           return 1;
       }
       else if(root->left){
           x=leftcount(root->left);
       }
       else if(root->right){
           y=leftcount(root->right);
       }
       x=leftcount(root->left);
        y=leftcount(root->right);
       return x+y;
}
Node* bst(Node* root,int key){
    if(root){
        if(root->data==key)
        {
            return root;
        }
        else if(root->data<key){
            return bst(root->right,key);
        }
        else {
            return bst(root->left,key);
        }
    }
    return NULL;
}
Node* ibst(Node* root,int key){
    while(root){
        if(root->data==key){
            return root;
        }
        else if(root->data<key){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return NULL;
}
int main(){
    create();
    postorder(root);
    cout<<endl<<countnode(root);
    cout<<endl<<height(root);
    cout<<endl<<leftcount(root);
    cout<<endl<<bst(root,3);
    cout<<endl<<ibst(root,3);
    return 0;
}
