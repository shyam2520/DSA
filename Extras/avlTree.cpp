#include<bits/stdc++.h>
using namespace  std;
struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
}*root;
Node* getnode(){
    Node* newnode=new Node;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int nodeheight(Node* creator){
    int hl=creator&&creator->left?creator->left->height:0;
    int hr=creator&&creator->right?creator->right->height:0;
    return hl>hr?hl+1:hr+1;
    
}
int balancefactor(Node* creator)
{
    // cout<<creator->right;
    int hl=creator&&creator->left?creator->left->height:0;
    int hr=creator&&creator->right?creator->right->height:0;
    // cout<<hl-hr;
    return hl-hr;
}
void LLRotation(Node* creator)
{
    Node* cl=creator->left;
    Node* clr=cl->right;
    cl->right=creator;
    creator->left=clr;
    creator->height=nodeheight(creator);
    cl->height=nodeheight(cl);
    if(root==creator){
        root=cl;
    }

}
void LRRotation(Node* creator)
{
    Node* cl=creator->left;
    Node* clr=cl->right;
    creator->left=clr->right;
    cl->right=clr->left;
    clr->left=cl;
    clr->right=creator;
    creator->height=nodeheight(creator);
    cl->height=nodeheight(cl);
    clr->height=nodeheight(clr);
    if(root==creator){
        root=clr;
    }
}
void RRRotation(Node* creator){
    Node *cr=creator->right,*crl=cr->left;
    cr->left=creator;
    creator->right=crl;
    creator->height=nodeheight(creator);
    cr->height=nodeheight(cr);
    if(root==creator)
    {
        root=cr;
    }
}
void RLRotation(Node* creator){
    Node* cr=creator->right;
    Node* crl=cr->left;
    creator->right=crl->left;
    cr->left=crl->right;
    crl->left=creator;
    crl->right=cr;
    cr->height=nodeheight(cr);
    crl->height=nodeheight(crl);
    creator->height=nodeheight(creator);
    if(root==creator)
    {
        root=crl;

    }
}

Node* create(Node* creator,int key){
    if(creator==NULL){
        creator=getnode();
        creator->height=1;
        creator->data=key;
        cout<<"done";
        return creator;
    }
    if(creator->data>key){
        creator->left=create(creator->left,key);
    }
    else if(creator->data<key){
        creator->right=create(creator->right,key);
    }
    creator->height=nodeheight(creator);
    // cout<<creator->height;
    if(balancefactor(creator) ==2&& (balancefactor(creator->left) - balancefactor(creator->right))==1)
    {
        // cout<<"ecexuting:";
        LLRotation(creator);
    }
    else if(balancefactor(creator)==2 && (balancefactor(creator->left)-balancefactor(creator->right) ==-1))
    {
        LRRotation(creator);
    }
    else if(balancefactor(creator)==-2 && (balancefactor(creator->left)-balancefactor(creator->right) ==-1))
    {
        RRRotation(creator);

    }
    else if(balancefactor(creator)==-2 && (balancefactor(creator->left)-balancefactor(creator->right) ==1)){
        RLRotation(creator);
    }
    return creator;
}
int main(){
    root=create(root,50);
    create(root,10);
    create(root,20);
    return 0;

}
