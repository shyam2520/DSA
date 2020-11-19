#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int l, int h,int mid){
    int i=l,j=mid+1,k=0;
    int b[100];
    while(i<=mid && j<=h){
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    for ( ; i <=mid; i++)
    {
        b[k++]=a[i];
        /* code */
    }
    for ( ; j <=h; j++)
    {
        b[k++]=a[j];
    }
    for (int i = 0; i <=h; i++)
    {
        a[l++]=b[i];
    }  
}
void itermerge(int a[], int n){
    int p;
    for( p=2;p<=n;p*=2){
        for (int i = 0; i+p-1 < n; i=i+p)
        {
           int l=i;
           int h=i+p-1;
           int mid=(l+h)/2;
           mergesort(a,l,h,mid);
        }
        
    }
    if(p/2<n){
        mergesort(a,0,n-1,p/2);
    }
}
void recmerge(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        recmerge(a,low,mid);
        recmerge(a,mid+1,high);
        mergesort(a,low,high,mid);
    }
}
int main(){
    int array[]={12, 11, 13, 5, 6, 7};
    recmerge(array,0,5);
    for (int i = 0; i < 6; i++)
    {
        cout<<array[i]<<endl;
    }
    
    return 0;
}