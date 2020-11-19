#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> g1;
    for (auto i = 0; i < 5; i++)
    {
        g1.push_back(i);
    }
    for (auto i = g1.begin(); i != g1.end(); i++)
    {
        *i=*i *2;
        //    cout<<endl<<typeid(i).name();
    }
     
    auto newposition=g1.insert(g1.begin(),8);
    g1.insert(newposition+2,9);
    for (auto i = g1.begin(); i !=g1.end(); i++)
    {
        /* code */
        cout<<*i;
    }
    cout<<endl<<endl;

    for (auto i = g1.rbegin(); i !=g1.rend(); i++)
    {
        /* code */
        cout<<*i;
    }   --

    cout<<endl<<g1[2];
    cout<<endl<<g1.at(4);
    
    
    vector<int> g2;
    g2.assign(5,12);
    for (auto i = g2.begin(); i !=g2.end(); i++)
    {
        cout<<*i;
    }
    
    
    
    return 0;
}