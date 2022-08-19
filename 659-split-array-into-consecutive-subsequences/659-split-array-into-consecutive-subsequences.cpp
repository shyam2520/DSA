class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> am,vm;
        // int groups=0;
        for(auto& i:nums) am[i]++;
        
        for(auto& i:nums)
        {
            if(am[i]<=0) continue;
            
            if(vm.count(i) && vm[i]>0 && am[i]>0)
            {
                am[i]--;
                vm[i]--;
                vm[i+1]++;
            }
            else if(am[i]>0 && am[i+1]>0 && am[i+1]>0) 
            {
                am[i]--;
                am[i+1]--;
                am[i+2]--;
                vm[i+3]++;
            }
            
        }
        
        for(auto& i:am) if(i.second) return false;
        
        
        return true;
    }
};