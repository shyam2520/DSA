class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // {100,4,200,1,3,2}
        // convert to unordered set 
        // find if each element is a start of seq 
        // on if so then expand to the right if not skip 
        unordered_set<int> uset(begin(nums),end(nums));
        int res =0;
        for(auto& i:uset){
            if(uset.find(i-1)!=uset.end()) continue; // not the start 
            else{
                int x =i+1;
                int cnt=1;
                while(uset.find(x)!=uset.end()) {
                    cnt++;
                    x++;
                }
                res=max(cnt,res);   
            }
        }
        return res;
    }
};