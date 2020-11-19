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
void treefrompre(int *pre,int n)
{
    Node* traverse=NULL;
    root=getnode();
    stack<Node*> address;
    int i=0;
    traverse=root;
    root->data=pre[i++];
    // address.push(INT16_MAX);
    address.push(root);
    while(i<n){
        if(pre[i]<traverse->data)
        {
            Node* temp=getnode();
            temp->data=pre[i++];
            traverse->left=temp;
            address.push(temp);
            traverse=temp;
        }
        else{
            if(pre[i]>traverse->data && pre[i]<address.top()->data)
            {
                Node* temp=getnode();
                traverse->right=temp;
                address.push(temp);
                traverse=temp;
            }
            else{
                traverse=address.top();
                address.pop();
            }
        }

    }
}