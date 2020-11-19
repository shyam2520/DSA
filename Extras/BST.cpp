#include<bits/stdc++.h>
using namespace std;
struct Node{
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
Node* insert(Node* root,int key)
{
    if(root==NULL){
        Node* temp=getnode();
        temp->data=key;
        return temp;
    }
    else if(root->data>key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}
void insertVal(Node* root,int key){
    Node *prev;
    if(!root)
    {
        root=getnode();
        root->data=key;
        return ;
    }
    else{
        while(root){
            prev=root;
            if(root->data>key){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    Node* temp=getnode();
    if (prev->data>key)
    prev->left=temp;
    else
    {
        prev->right=temp;
    }
    temp->data=key;

}
void inorder(Node* root)
{
    if(root)
    {inorder(root->left);
    cout<<root->data;
    inorder(root->right);}
}
int node_height(Node* root){
    if (root==NULL) 
    {
        return 0;
    }
    else{
        int x=node_height(root->left);
        int y=node_height(root->right);
        if(x>y){
            return x+1;
        }
        else {
            return y+1;
        }
    }
}
Node* inorder_predcessor(Node* p)
{
    while(p && p->right!=NULL){
        p=p->right;
    }
    return p;

}
Node* inorder_succesor(Node* p)
{
    while(p && p->left!=NULL){
        p=p->left;
    }
    return p;

}
Node* node_delete(Node* traverse,int key)
{
    Node* replacement=NULL;
    if(traverse==NULL){
        return NULL;
    }
    else if(traverse->left==NULL && traverse->right==NULL){
        if(traverse==root){
            root=NULL;
        }
        delete traverse;
        return NULL;
    }

   else
   {
       if(traverse->data>key){
        traverse->left=node_delete(traverse->left,key);
    }
    else if( traverse->data<key){
        traverse->right=node_delete(traverse->right,key);
    }
    else{
        if(node_height(traverse->left)>node_height(traverse->right))
        {
            replacement=inorder_predcessor(traverse->left);
            traverse->data=replacement->data;
            traverse->left==node_delete(traverse->left,replacement->data);
        }
        else{
            replacement=inorder_succesor(traverse->right);
            traverse->data=replacement->data;
            traverse->right==node_delete(traverse->right,replacement->data);

        }
    }
   }
    
    return traverse;
}

int main(){
    Node* root=NULL;
    root=insert(root,10);
    // cout<<root<<endl; 
    cout<<endl<<insert(root,90 );
    cout<<endl<<insert(root,20)<<endl;
    insert(root,80);
    insertVal(root,30);
      inorder(root);
      cout<<endl;
    node_delete(root,10);
    inorder(root);

    return 0;
}