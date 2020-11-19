#include<bits/stdc++.h>
using namespace std;
void insert(int hashtable[],int key )
{
    int index=key%10;
    int secondindex=7-(key%7);
    int i=0;
    while(hashtable[index]!=0){
        index=(index+i*secondindex)%10;
        i++;
    }
    hashtable[index]=key;

}
int main(){
    int hashtable[10]={0};
    insert(hashtable,25);
    insert(hashtable,35);
    insert(hashtable,45);
    insert(hashtable,95);
    return 0;
}