class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> uset(begin(nums),end(nums));
        for(auto& i:uset){
            int len=0;
            int a=i-1,b=i+1;
            while(uset.find(a)!=uset.end()){
                uset.erase(a);
                a--;
                len++;
            } 
                
            while(uset.find(b)!=uset.end()){
                uset.erase(b);
                b++;
                len++;
            } 
            res=max(res,len+1);
        }
        return res;
    }
};