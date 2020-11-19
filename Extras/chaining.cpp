#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
};
Node* getnode(){
    Node* newnode=new Node;
    newnode->right=NULL;
    return newnode;
}
void sortedInsert(Node*& root,int key)
{
    Node* prev=NULL;
    if(root==NULL){
        root=getnode();
        root->data=key;

    }
    else{
        while(root!=NULL && root->data<key)
        {
            prev=root;
            root=root->right;
        }
        Node* newnode=getnode();
        newnode->data=key;
        newnode->right=prev->right;
        prev->right=newnode;
        root=prev;
    }
}
void searchnode(Node* root,int key){
    if(root->data==key){
        cout<<root<<endl<<root->data;
    }
    else{
        while(root && root->data!=key)
        {
            root=root->right;
        }
        cout<<root<<endl<<root->data;
    }
}
void insert(Node* array[],int key)
{
    int index=key%10;
    sortedInsert(array[index],key);
}
void search(Node* array[],int key){
    int index=key%10;
    searchnode(array[index], key);
}
int main(){     
    Node* array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i]=NULL;
    }
    insert(array,12);
    insert(array,22);
    insert(array,13);
    // cout<<array[2]->data<<end;
    search(array,22);
    search(array,243);
    return 0;
}