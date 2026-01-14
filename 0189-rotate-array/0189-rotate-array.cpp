class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(begin(nums),end(nums));
        int n = nums.size(); 
        k=k>n?k%n:k; 
        reverse(begin(nums),begin(nums)+k); 
        reverse(begin(nums)+k,end(nums));

    }
};