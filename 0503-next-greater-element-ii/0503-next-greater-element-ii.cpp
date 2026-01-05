class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;
        int n = nums.size();
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        vector<int> res(n,-1);
        for(int i=0;i<nums.size();i++){
            while(stack.size() && nums[stack.top()]<nums[i]){
                if(stack.top()<n) res[stack.top()]=nums[i];
                stack.pop();
            }
            stack.push(i);
        }

        return res;
    }
};