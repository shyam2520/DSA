// #include <stdio>
#include<iostream>
using namespace std;
int sum(int n){
    return sum(n-1)+n;
}
int main(){
    int n=5;
    int k=sum(5);
    cout<<"hello";
    printf("%d",k);
}