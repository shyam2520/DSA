class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans=0;
        unordered_set<int> n(begin(nums),end(nums));
        unordered_map<int,int> dict;
        for(auto& i:n)
        {
            int count=0;
            int temp=i;
            while(temp) 
            {
                count+=temp&1;
                temp>>=1;
            }
            dict[count]++;
            // cout<<count<<" "<<dict[count].size()<<endl;;
            
        }
        
        for(int i=1;i<=30;i++)
        {
            for(int j=1;j<=30;j++)
            {
                if(i+j<k || !dict[i] ||!dict[j]) continue;
                ans+=dict[i]*dict[j];
            }
        }
        return ans;
    }
};