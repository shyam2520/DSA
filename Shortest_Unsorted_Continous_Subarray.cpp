class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> index;
        int start=nums.size()-1,end=0;
        for(int i=0;i<nums.size();)
        {
            if(index.empty())
                index.push(i++);
            else 
            {
                if(nums[index.top()] > nums[i])
                {
                    start =min(start,index.top());
                    index.pop();
                }
                else
                    index.push(i++);
            }
        }
        while(!index.empty()) index.pop();
        for(int i=nums.size()-1;i>=0;)
        {
            if(index.empty())
                index.push(i--);
            else 
            {
                if(nums[index.top()]<nums[i])
                {
                    end=max(end,index.top());
                    index.pop();
                }
                else
                    index.push(i--);
            }
        }
        if(start>=end) return 0;
        return end-start+1;
    }
};