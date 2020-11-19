#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int h){
    int i=l,j=h;
    int pivot=a[l];
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j){
            swap(a[i],a[j]);
        }
    }while(i<j);
    swap(a[j],a[l]);
    return j;
}
void quicksort(int a[],int l,int h){
    if(l<h){
        int j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}
int main(){
    int A[]={2,3,16,4,17,9,1,INT32_MAX},n=8;
    quicksort(A,0,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<A[i];
    }
    
    return 0;
}