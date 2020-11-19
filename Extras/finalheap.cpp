#include<bits/stdc++.h>
using namespace std;
void insert(int heap[],int i){
    int parent=i/2;
    int temp=heap[i];
    while(i>1 && temp>heap[i/2])
    {
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=temp;
}
void delete_val(int heap[],int size)
{
    int highest=heap[1];
    int lowest=heap[size];
    heap[1]=heap[size];
    heap[size]=highest;
    int i=1, j=2*i;
    while(j<size-1)
    {
        if(heap[j]<heap[j+1])
        {
            j=j+1;

        }
        if(heap[j]>heap[i]){
            swap(heap[i],heap[j]);
            i=j;
            j=2*j;
        }
        else{
            break;
        }

    }

}
int main()
{
    int heap[]={0,10,20,30,40,50};
    for (int i = 2; i <=5; i++)
    {
        insert(heap,i);
    }
    for (int i = 5; i>1; i--)
    {
        delete_val(heap,i);
        /* code */
    }
    
    for (int i = 1; i <=5; i++)
    {
        cout<<heap[i];
    }
    // cout<<hea
    

    return 0;
}