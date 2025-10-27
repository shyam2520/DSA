class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        nums.push_back(INT_MAX);
        map<int,int> dict; 
        for(auto& i:nums) dict[i]++; 
        int prev=INT_MAX;
        int cnt=0,res=0;
        for(auto& i:dict){
            int key = i.first; 
            if(prev==INT_MAX || key==1+prev){
                cnt++;
                prev=key;
            }
            else{
                res=max(res,cnt);
                cnt=1;
                prev=key;
            }
        }

        return res;
    }
};