class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        q.push({nums[0],0});
        for(int i=1;i<nums.size();i++)
        {
            while(q.size() && i-q.top().second>k) q.pop();
            q.push({q.top().first+nums[i],i});
        }
        while(q.size() && q.top().second!=nums.size()-1) q.pop();
        return q.top().first;
    }
};