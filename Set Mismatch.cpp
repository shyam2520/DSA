class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            // we are using the value-1 and making negative to indicate that it is already visited and next time if we encounter it 
            // that means we have already visited so that's the duplicate element and the only positive element in the array whose 
            // index+1 will be the missing value 
            int index=abs(nums[i])-1;
            if(nums[index]<0)
                ans.push_back(index+1);
            else 
                nums[index]=-nums[index];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};