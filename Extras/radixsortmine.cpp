#include<bits/stdc++.h>
using namespace std;
void countsort(int array[],int exp,int n){
    int output[n];
    int count[10]={0};
    for (int i = 0; i < n; i++)
    {
        count[(array[i]/exp)%10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i]+=count[i-1];
    }
    for (int i = n-1; i >=0; i--)
    {
        output[count[(array[i]/exp)%10]-1]=array[i];
        count[(array[i]/exp)%10]--;
    }
    for (int i = 0; i < n; i++)
    {
        array[i]=output[i];
    }
   
    
    
    
    
}
void radixsort(int array[],int n){
    int max=*max_element(array,array+n);
    for (int exp = 1; max/exp >0; exp*=10)
    {
        countsort(array,exp,n);
    }
    

}
int main(){
    int array[]={170,45,75,90,802,24,2,66};
    int n=sizeof(array)/sizeof(array[0]);
    radixsort(array,n);
     for (int i = 0; i < n; i++)
    {
        cout<<array[i];
    }
}