class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(),curridx;
        vector<int> res(n,-1);
        stack<int> stack;
        for(int i=0;i<(2*n);i++){
            // curridx=i%n;
            while(stack.size() && nums[stack.top()%n]<nums[i%n]){
                res[stack.top()%n]=nums[i%n];                
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};