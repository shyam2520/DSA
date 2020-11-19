#include<bits/stdc++.h>
using namespace std;
int findsum(vector<int>& nums,int k)
{
    int n=nums.size();
    map<int,int>mp;
    int curr_sum=0,total=0;
    for(int i=0;i<n;i++){
        curr_sum+=nums[i];
        
        if(curr_sum==k)
        {    
            total+=1;
        }
        if(mp.find(curr_sum-k)!=mp.end()){
            total+=mp[curr_sum-k];
        }
        mp[curr_sum]++;
        //    cout<< mp[curr_sum]++;
           cout<<curr_sum<<"\t"<<mp[curr_sum]<<endl;
    }
 return total; 
}
int main(){
    // map<int,int> mp;
    // mp.insert(pair<int,int>(1,40));
    // mp.insert(pair<int,int> (2,60));
    // for (auto i = mp.begin(); i != mp.end(); i++)
    // {
    //     cout<<i->first<<"\t"<<i->second<<endl;
    // }
    vector<int> vc{15,2,4,8,9,5,10,23};
    cout<<findsum(vc,23);
    return 0;
}