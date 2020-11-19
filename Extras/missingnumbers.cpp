#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n;
    cin>>n;
    long int array[n-1];
    long int actual_sum=n*(n+1)/2;
    for (int i = 0; i <n-1 ; i++)
    {
        cin>>array[i];
    }
    long int missing_sum=0;
    for (int i = 0; i < n-1; i++)
    {
        missing_sum+=array[i];
    }
    cout<<actual_sum-missing_sum;
    
}