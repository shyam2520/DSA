class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // 1. consider each element to be the end elment of the subarr
        // 2. calculate min length of the subarray for each element 
        // 3. so every thing longest sub array -min len subar would get total valid subarray 
        // 4. just add 1 extra since we are subtracting min len subarray  as well 
        int n=nums.size();
        unordered_map<int,int> dict;
        vector<int> minlen(n,0);
        int anc=0,res=0;
        for(int i=0;i<n;i++){
            dict[nums[i]]++;
            int prevanc=-1;
            while(anc<=i && dict.size()>k){
                // if(dict.size()==k) prevanc=anc;
                dict[nums[anc]]--;
                if(!dict[nums[anc]]) dict.erase(nums[anc]);
                anc++;
            }
            if(dict.size()==k){
                while(anc<=i && dict[nums[anc]]-1!=0){
                    dict[nums[anc]]--;
                    anc++;
                }
                minlen[i]=i-anc+1;
            }

        }
        dict.clear();
        anc=0;
        for(int i=0;i<n;i++){
            dict[nums[i]]++;
            while(anc<=i && dict.size()>k){
                dict[nums[anc]]--;
                if(!dict[nums[anc]]) dict.erase(nums[anc]);
                anc++;
            }
            if(dict.size()==k){
                int max_len = i-anc+1;
                int min_len = minlen[i];
                res+=max_len-min_len+1;
            }
        }
        return res;

    }
};