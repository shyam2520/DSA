class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> res(begin(nums),end(nums));
        int prev,next;
        int len=0;
        for(auto& i:nums)
        {
            if(res.find(i)==res.end()) continue;
            res.erase(i);
            prev=i-1;
            next=i+1;
            while(res.find(prev)!=res.end()) prev--;
            while(res.find(next)!=res.end()) next++;
            len=max(len,next-prev-1);
        }
        return len;
    }
};