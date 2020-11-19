#include<bits/stdc++.h>
using namespace std;
int probe(int hastable[],int key){

    int index=key%10;
    int i=index;
    while(hastable[i]!=0)
    {
        i++;   
    }
    return i;
}
void insert(int hashtable[],int key){
    int index=key%10,newindex=0;
    if(hashtable[index]!=0)
    {
        index=probe(hashtable,key);
    }
    hashtable[index]=key;

}
int search(int hashtable[],int key){
    int index=key%10;
    while(hashtable[index]!=key&& hashtable[index]!=0)
    {
        index++;
    }
    return index;
}
int main(){
    int hashtable[10]={0};
    insert(hashtable,12);
    insert(hashtable,22);
    insert(hashtable,36);
    cout<<search(hashtable,22);
    return 0;
}