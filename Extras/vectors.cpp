#include<iostream>
// #include<stdio>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1{3,2,4,-1,1};  
    vector<vector<int>> vap;
    auto new_end=std::find(v1.begin(),v1.end(),-1);
    // int index=std::distance(v1.begin(),new_end);
    // new_end=v1.begin()+new_end;
    vector<int> ans(3);
    copy(v1.begin(),new_end,ans.begin());

    for (auto i = ans.begin(); i !=ans.end(); i++)
    {
        cout<<*i<<endl;
    }

    
   
    return 0;
}