#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
void show(int arr[],int arrsize){
    for (int i = 0; i < arrsize; i++)
    {
        cout<<arr[i];
    }
    
}
bool descend(int x, int y){
    return x>y;
}
 int main(){
     int arr[]={6,4,3,2,1,-5};
     int arrsize=sizeof(arr)/sizeof(arr[0]);
     sort(arr, arr+arrsize);
     show(arr,arrsize);
     cout<<binary_search(arr,arr+arrsize,13);
     reverse(arr,arr+arrsize);
     show(arr,arrsize);
   //functions will works for arrays and vectors 
     all_of(arr,arr+arrsize,[](int i){return i>0;})? cout<<"all are postive": cout<<"all are negative"<<endl;
    any_of(arr,arr+arrsize,[](int x){return x>0;})?cout<<"at least one of the me is negative":cout<< "0"<<endl;
    none_of(arr,arr+arrsize,[](int x){return x<0;})?cout<<"none satisfy": cout<<"one satisfies"<<endl;
    int newarr[6]={0};
    iota(newarr,newarr+arrsize,20);
    cout<<endl<<endl;
    show(newarr,arrsize);
    int copy[6]={0};
    copy_n(arr,arrsize,copy);
    cout<<endl<<endl;
    //vectors
    vector<int> v{10,20,30,40};
    sort(v.begin(),v.end(),descend);
    for(int x:v){
        cout<<x<<endl;
    }
    show(copy,arrsize);

    // sets
    set<int> random;
    random.insert(14);
    random.insert(5);
    random.insert(6);
    random.insert(7);
    random.insert(8);
    for(int x: random){
        cout<<x<<endl;
    }
    auto it=random.find(14);
    if(it!=random.end())
    {
        cout<<"\npresent";

    } 
    else{
        cout<<"\nnot present";
    }
    auto it2=random.upper_bound(7);
    cout<<*it2;
    map<char,int> dict;
    string s="shyam mylai";
    for(char c : s){
        dict[c]++;
    }
    cout<<"\n"<< dict['m'];
    vector<pair<int,int>> vr;
    vr.push_back(make_pair(10,20));
    vr.push_back(make_pair(21,30));
    cout<<endl;
    for(auto x : vr){
      cout<<x.first<<"\t"<<x.second<<endl;
    }
    int find_range=25;
    auto itr=upper_bound(vr.begin(),vr.end(),make_pair(find_range,INT_MAX));
    if(itr==vr.begin()){
        cout <<"not found ";
        return 0 ;
    }
    itr--;
    pair<int,int> current=*itr;
    if(current.first<find_range && find_range<current.second){
        cout<<"found in the range \t"<<current.first<<"\t"<<current.second;
    }

     return 0;
 }