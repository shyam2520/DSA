class Solution {
public:
    string largestOddNumber(string nums) {
        int n=nums.size(),i; 
        for(i=n-1;i>=0;i--) if((nums[i]-'0')%2) break;
        return nums.substr(0,i+1);
    }
};