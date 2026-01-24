class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset; 
        for(auto& i:nums) uset.insert(i); 
        int res = 0,cnt=0;
        for(auto& i:uset){
            if(uset.find(i-1)==uset.end()) {
                int val = i+1;
                cnt=1;
                while(uset.find(val)!=uset.end()){
                    val++;
                    cnt++;  
                }
                res=max(res,cnt);
            }
            else continue;
        }
        return res;
    }
};