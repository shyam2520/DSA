#include<iostream>
#include<stdio.h>
using namespace std;
int sum(int n){
    if(n==0)
    {
        return 1;
    }
    return sum(n-1)*n;
}
int main(){
    int k=sum(5);
    cout<<"random";
    cout<<k;
    return 0;
}