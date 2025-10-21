class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int anc=0;
        for(int i=0;i<nums.size();i++){
            nums[anc]=nums[i++];
            while(i<nums.size() && nums[i]==nums[anc]) i++;
            anc++;
            i--;
        }
        nums.resize(anc);
        return anc;
    }
};