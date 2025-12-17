class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // queue which keep track of the window
        // if a new elment is greater than rest of the elements pop all front
        // values in the queu;
        vector<int> res;
        deque<int> maxq;

        for (int i = 0; i < nums.size(); i++) {
            // insert at either front or back of queue
            if (maxq.size() && nums[i] >= nums[maxq.front()]) {
                while (maxq.size() && nums[i] >= nums[maxq.front()]) {
                    maxq.pop_front();
                }
                maxq.push_front(i);
            }
            else{
                while(maxq.size() && nums[i]>=nums[maxq.back()]) maxq.pop_back();
                maxq.push_back(i);
            }
            if (i+1 >= k) {
                while(maxq.size() && maxq.front()<(i-k+1)) maxq.pop_front();
                res.push_back(nums[maxq.front()]);
            }
        }

        // insert to queue
        // pop if the max crosses window
        // push to res
        return res;
    }
};