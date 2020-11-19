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
void create()
{
    int left,right;
    queue<Node*> address;
    root=getnode();
    cout<<"enter the root node";
    cin>>root->data;
    address.push(root);
    while(!address.empty())
    {
        Node* p=address.front();
        address.pop();
        cout<<"Enter left node";
        cin>>left;
        if(left!=-1){
            Node* leftnode=getnode();
            leftnode->data=left;
            address.push(leftnode);
            p->left=leftnode;

        }
        cout<<"Enter right node";
        cin>>right;
        if(right!=-1){
            Node* rightnode =getnode();
            rightnode->data=right;
            address.push(rightnode);
            p->right=rightnode;
        }

    }
    
}
void iterativepreorder(Node* head){
    stack<Node*> address;
    // cout<<head;
    while(head || !address.empty())
    {
        if(head){
            cout<<head->data;
            address.push(head);
            head=head->left;
        }
        else if(head==NULL){
            head=address.top();
            address.pop();
            head=head->right;
        }
    }
}
void iterativeinorder(Node* head){
    stack<Node*> address;
    while(head || !address.empty()){
        if(head){
            address.push(head);
            head=head->left;
        }
        else if(head==NULL){
            head=address.top();
            address.pop();
            cout<<head->data;
            head=head->right;
            // address.pop();
        }
    }
}
void postordertraversal(Node* head){
    stack<Node*> stack1,stack2;
    stack1.push(head);
    // cout<<stack1.top()->data;
    while(!stack1.empty()){
        head=stack1.top();
        stack1.pop();
        stack2.push(head);
        if (head->left && head->right){

            stack1.push(head->left);
            stack1.push(head->right);

        }
        else if(head->right){
            // stack1.push(head->left);
            cout<<"\nhead-> right executed\n";
            stack1.push(head->right);

        }
        else if(head->left)
        {
            cout<<"\nhead-> right executed\n";
            stack1.push(head->left);
            
        }
    }
    while(!stack2.empty())
    {
        cout<<stack2.top()->data;
        stack2.pop();
    }
}
void levelorder(Node* root){
    queue<Node*> address;
    address.push(root);
    cout<<root->data;
    while(!address.empty()){
        Node* current=address.front();
        address.pop();
        if(current->left)
        {
            cout<<current->left->data;
            address.push(current->left);
        }
        if(current->right){
            cout <<current->right->data;
            address.push(current->right);

        }
    }

}
int main(){
    create();
    cout<<"preorder traversal";
    iterativepreorder(root);
    cout<<endl;
    cout<<"inorder trversal \n";
    iterativeinorder(root);
    cout<<"\npost order travesal"<<endl;
    postordertraversal(root);
    levelorder(root);
    return 0;
}
