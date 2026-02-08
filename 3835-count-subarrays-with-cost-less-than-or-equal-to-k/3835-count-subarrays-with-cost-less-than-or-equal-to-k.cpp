class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // you need l...r which is within the range if so then we consider if not we would increment l 
        // and for that window in O(1)-> we get min & max using deque 
        deque<int> minq,maxq;
        int l=0,r,n=nums.size();
        long long res =0;
        for(int r=0;r<n;r++){
            while(minq.size() && nums[minq.front()]>=nums[r]) minq.pop_front();
            minq.push_back(r);
            while(maxq.size() && nums[maxq.front()]<=nums[r]) maxq.pop_front();
            maxq.push_back(r);
            while(l<=r && (long long)(r-l+1)*(long long)((nums[maxq.front()]) - nums[minq.front()])>k){
                while(minq.size() && minq.front()<=l) minq.pop_front();
                while(maxq.size() && maxq.front()<=l) maxq.pop_front();
                l+=1;
            }
            res+=r-l+1;
        }
        return res;
    }
};