class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> sliding_window;
        // ____..__ of size K which will have values constantly inputed and checks the corresponding number which will give the value <=t
        for(int i=0;i<nums.size();i++){
            
            long n=nums[i];// to prevents overflow in subraction of INT_MAX-INT_MIN
            if(i>k){
                sliding_window.erase(nums[i-k-1]);
                //removing starting value so that you can slide the window
            }
            auto pos=sliding_window.lower_bound(n-t);
            if(pos!=sliding_window.end() && abs(*pos-n)<=t)
            {
                return true;
            }
            sliding_window.insert(n);
        }
        
        return false;
    }
};