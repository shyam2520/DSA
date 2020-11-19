#include<bits/stdc++.h>
using namespace std;
int main(){
    // set<int,greater<int>> s;
    // s.insert(10);
    // s.insert(20);
    // s.insert(30);
    // s.insert(40);
    // s.insert(50);
    // s.insert(50);
    // for(int x: s){
    //     cout<<x;
    // }
    multiset<int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(30);
    ms.insert(40);
    ms.insert(40);
    ms.insert(40);
    for(int x:ms){
        cout<<x;
    }
    multimap<int,int> count_val;
    count_val.insert(pair<int,int>(1,20));
    count_val.insert(pair<int,int>(1,30));
    for (auto i = count_val.begin(); i!=count_val.end(); i++)
    {
        cout<<i->first<<"\t"<<i->second;
    }
    unordered_set<int> uset;
    uset.insert(10);
    uset.insert(40);
    uset.insert(2);
    uset.insert(25);
    if(uset.find(2)==uset.end()){
        cout<<"not found";
    }
    cout<<endl;
    cout<<endl<<"values"<<endl;
    for (auto i = uset.begin(); i !=uset.end(); i++)
    {
        cout<<*i<<endl;
    }
    

    unordered_multiset<int> umset;
    umset={1,11,2,3,33,34,4,4,4,9};
    cout<<umset.count(4);
    for(int x: umset){
        cout<<x<<endl;
    }

    unordered_map<string,int> um;
    um["fire"]=2;
    um["water"]=3;
    for (auto i = um.begin(); i !=um.end(); i++)
    {
        cout<<i->first<<"\t"<<i->second;
    }
    unordered_multimap<int,int> ummp;
    ummp.insert(pair<int,int>(23,32));
    ummp.insert(pair<int,int>(23,35));
    for (auto i = ummp.begin(); i !=ummp.end(); i++)
    {
        cout<<i->first<<"\t"<<i->second;
    }
    
    

}   