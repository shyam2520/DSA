class Solution {
public:
    bool inValidChange(int bill,unordered_map<int,int>& dict){
        int arr[3]={5,10,20};
        unordered_map<int,int> cpy = dict;
        for(int i=2;i>=0 && bill;i--){
            if(cpy[arr[i]]){
                int change = min(cpy[arr[i]],bill/arr[i]);
                cpy[arr[i]]-=change;
                bill-=arr[i]*change;
            }
        }
        if(bill) return true;
        dict=cpy;
        return false;
    }
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> dict;
        for(auto& bill:bills){
            if(bill==5) dict[bill]++;
            else{
                if(inValidChange(bill-5,dict)) return false;
                dict[bill]++;
            }
        }
        return true;
    }
};