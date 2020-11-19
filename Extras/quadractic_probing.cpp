#include<bits/stdc++.h>
using namespace std;
void insert(int hashtable[],int key){
    int index=key%10;
    int i=0;
    while(hashtable[index]!=0)
    {
        index=(hashtable[index]%10+i*i)%10;
        i++;
    }
    hashtable[index]=key;

}
int search(int hashtable[],int key)
{
    int index=key%10;
    int i=0;
    while (hashtable[index]!=0)
    {
        if(hashtable[index]!=key){
            index=(hashtable[index]%10+i*i)%10;
            i++;
        }
        else{
            return index;
        }
        
    }
    return -1;
}

int main(){
    int hashtable[10]={0};
    int key;
    insert(hashtable,12);
    insert(hashtable,22);
    cout<<search(hashtable,22);
    return 0;
}