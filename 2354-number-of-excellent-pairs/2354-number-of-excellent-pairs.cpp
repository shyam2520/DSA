class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,unordered_set<int>> dict;
        for(auto& i:nums)
        {
            int count=0;
            int temp=i;
            while(i) 
            {
                count+=i&1;
                i>>=1;
            }
            dict[count].insert(temp);
            // cout<<count<<" "<<dict[count].size()<<endl;;
            
        }
        
        for(int i=1;i<=30;i++)
        {
            for(int j=1;j<=30;j++)
            {
                if(i+j<k || !dict[i].size() ||!dict[j].size()) continue;
                ans+=dict[i].size()*dict[j].size();
            }
        }
        return ans;
    }
};