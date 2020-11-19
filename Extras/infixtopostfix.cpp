#include<bits/stdc++.h>
using namespace std;
int operation(char c){
    if(c=='*'|| c=='+' || c=='-' || c=='+'||c=='/')
    return 1;
    else 
    return 0;
}
int pre(char c){
    if(c=='*' || c== '/')
    {return 1;}
    else if ( c=='+' || c=='-')
    {return 0;}
    else if (c=='^')
    {return 3;}
    // return ;
    return -1;
}
char* intopost(char *infix){
    char* post=new char[strlen(infix)+2];
    int i=0,j=0;
    std::stack<char> op;
    op.push('r');
    while(infix[i]!='\0')
    {
        if(operation(infix[i]))
        {
            // cout<<infix[i]<<endl;
            if(pre(op.top())<pre(infix[i]))
            { 
                op.push(infix[i]);
                // cout<<op.top();
                i++;
            }
            else{
                char c=op.top();
                op.pop();
                post[j]=c;
                j++;
            }
        }
        else{
            post[j]=infix[i];
            i++;
            j++;
        }
       
        
    }
    // cout<<op.top();
    while(!op.empty()&&op.top()!='r')
    {
        // cout<<op.top();
        post[j]=op.top();
        op.pop();
        j++;
    }
     post[j]='\0';
    return post;


}
int main(){ 
    char* infix="a+b*c-d/e";
    // cout<<infix;
    char *pot=intopost(infix);
    cout<<pot;
    return 0;
}