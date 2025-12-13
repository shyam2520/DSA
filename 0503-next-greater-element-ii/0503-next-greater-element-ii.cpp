class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> newnums=nums;
        for(auto& i:nums){
            newnums.push_back(i);
        }   
        stack<int> stack; // storing indices for updating nums striaght away 
        for(int i=0;i<newnums.size();i++){

            while(stack.size() && newnums[stack.top()]<newnums[i])
            {
                int nnidx = stack.top();
                if(nnidx<nums.size()){
                    nums[nnidx]=newnums[i];
                }
                stack.pop();
            }
            stack.push(i);
        }
        while(stack.size()){
            if(stack.top()<nums.size()) nums[stack.top()] = -1;
            stack.pop();
        }
        return nums;
    }
};