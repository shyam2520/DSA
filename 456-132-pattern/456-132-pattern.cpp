class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> stack;
        int min_val=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(stack.empty()) stack.push({nums[i],min_val});
            else
            {
                while(stack.size() && stack.top().first<=nums[i])
                {
                    min_val=min(min_val,stack.top().first);
                    stack.pop();
                }
                if(stack.size() && stack.top().second<nums[i]) return true;
                stack.push({nums[i],min_val});
            }
        }
        return false;
    }
};