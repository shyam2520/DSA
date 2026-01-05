class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        int n = nums.size();
        vector<int> res; 
        for(int i=0;i<n;i++){
            // remove any values which out of window
            while(dq.size() && dq.front()<=i-k){
                dq.pop_front();
            }
            // if current value is greater that all the values in the window pop 
            while(dq.size() && nums[dq.front()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i+1>=k) res.push_back(nums[dq.front()]);
        }

        return res;
    }
};